# Gstreamer  
gst_rtmp_to_rtmp_main.cpp source kodun bulunduğu dosyadır. 

# Derlemek için  
git clone https://github.com/Muhammed-Salih-Karademir/gstreamer_rtmp_to_rtmp_4dsight  
cd gstreamer/gstreamer-01  
mkdir build; cd build  
cmake ../  
make  
./gstreamer-01  

# İlgili basit Gstreamer Pipeline'ı Transmuxing  
gst-launch-1.0 -v rtmpsrc location=rtmp://34.105.124.140:1935/live/pri_test ! queue2 ! flvdemux name=demux flvmux name=mux demux.video ! queue ! mux.video demux.audio ! queue ! mux.audio mux.src ! queue ! rtmpsink location='rtmp://live.twitch.tv/app/live_625459812_I8fN8HStRFsCfwf1YrTM9MmDX4d5cK'  
