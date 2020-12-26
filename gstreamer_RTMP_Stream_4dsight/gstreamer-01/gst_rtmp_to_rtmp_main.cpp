#include <iostream>
#include <gst/gst.h>

int main(int arg, char *argv[]) {
    GstElement *pipeline = nullptr;
    GstBus *bus = nullptr;
    GstMessage *msg = nullptr;

    // gstreamer initialization
    gst_init(&arg, &argv);

    // building pipeline
    pipeline = gst_parse_launch(
            /*Transmuxing */
            "rtmpsrc location=rtmp://34.105.124.140:1935/live/pri_test ! queue2 ! flvdemux name=demux flvmux name=mux demux.video ! queue ! mux.video demux.audio ! queue ! mux.audio mux.src ! queue ! rtmpsink location=rtmp://live.twitch.tv/app/live_625459812_I8fN8HStRFsCfwf1YrTM9MmDX4d5cK",
            nullptr);
    
    // start playing
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    printf("Yayin Muhammed Salih Karademir twitch kanalında baslamistir. Mail ile gönderilen linkten erisebilirsiniz.\n");
    //wait until error or EOS ( End Of Stream )
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     static_cast<GstMessageType>(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));
    
    

    // free memory
    if (msg != nullptr)
        gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
