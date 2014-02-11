//reads lines from the serial port or http url
//inputs are in the format
//control_id,control_value[0-100]

//Map controls to pins
//green=3, red=5, blue=6
//control_id is the same as arduino pin_id
int allowed_controls[]= {3,5,6};
int allowed_controls_num = (sizeof(allowed_controls)/sizeof(int *));

//Search first ocurrence in an array
int array_search(int a_controls[], int value)
{
  int i=0;
  for(i=0; i < allowed_controls_num; i++)
  {
    if(a_controls[i] == value)
    {
      return i;
    }
  }
  return -1;
}

//Reads a line from the serial port
String sp_read()
{
  String line = "";
  while (Serial.available() > 0)
  {
    line = line + char(Serial.read());
    //Add this delay to ensure that all the values are read
    delay(10);
  }
  return line;
}

//Convert String to number
long string2long(String string){
  char cadena[string.length()+1];
  string.toCharArray(cadena, string.length()+1);

  return atol(cadena);
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //Local variables
  String control_id;
  String control_value;
  int separator_position;
  int brightness;
  //Reads the serial port
  String msg = sp_read();

  //Looks for the coma
  //inputs are in the format
  //control_id,control_value[0-100]  separator_position = message.indexOf(',');
  separator_position = msg.indexOf(',');
  if(separator_position != -1)
  {
    control_id = msg.substring(0, separator_position);
    control_value = msg.substring(separator_position+1);
    //Serial.println("msg: " + msg);
    //Serial.println("Control_id: " + control_id);
    //Serial.println("Control_value: " + control_value);

    //map the brigness input range (0-9) to the analogWrite range (0-255)
    if(array_search(allowed_controls, (int)string2long(control_id)) != -1)
    {
      pinMode(string2long(control_id),OUTPUT);
      brightness = map(string2long(control_value),0,100,0,255);
      analogWrite(string2long(control_id),brightness);
    }

  }

}

