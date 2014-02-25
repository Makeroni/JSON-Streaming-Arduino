$(document).ready(function(){

    //xively-js
    //http://xively.github.io/xively-js/
    var feedID        = 1774687405;          // Feed ID

    xively.setKey( "OHQFWQFYqwfSPHBOL2VD1ChpYQzUZ4wiIZfhRYZd1uVmwRwb" );


    function update_color(){
        //get rgb values mapped to 256
        var r_val = Math.round((255/100) * ($('#c_1').val()));
        var g_val = Math.round((255/100) * ($('#c_2').val()));
        var b_val = Math.round((255/100) * ($('#c_3').val()));

        //Update the color_box background
        $('#color_box').css('background-color','rgb('+r_val+','+g_val+','+b_val+')');

        //var my_json = '{"version":"1.0.0",            "datastreams" : [ {            "id" : "red",            "datapoints":[                {"at":"2013-04-22T01:35:43Z","value":"83"}            ],            "current_value" : "83"        }        ]    }';

        //updates the value to xively
        switch(this.id)
        {
            case 'c_1':
                //xively.datapoint.new (feedID, 'red', my_json, function(){});
                break;
            case 'c_2':
                //xively.datapoint.new (feedID, 'green', my_json, function(){})
                break;
            case 'c_3':
                //xively.datapoint.new (feedID, 'blue', my_json, function(){})
                break;
        }

        //Update Zone 1 stream
        xively.feed.get(feedID, function(data){
            $('#zone_1').html($.param(data));
        });


    }


    //Event handler
    $('input[type="range"]').change(update_color);

    //onload get random values
    $('#c_1').val(Math.random()*100);
    $('#c_2').val(Math.random()*100);
    $('#c_3').val(Math.random()*100);
    update_color();


});


