#Gstreamer
İlgili basit Gstreamer Pipeline'ı Transmuxing gst-main.cpp source kodun bulunduğu dosyadır. gstreamer-01 ise derlenmiş C dosyasıdır.

#Derlemek için
git clone https://github.com/karthickai/gstreamer.git
cd gstreamer/gstreamer-01
mkdir build; cd build
cmake ../
make
./gstreamer-01

gst-launch-1.0 -v rtmpsrc location=rtmp://34.105.124.140:1935/live/pri_test ! queue2 ! flvdemux name=demux flvmux name=mux demux.video ! queue ! mux.video demux.audio ! queue ! mux.audio mux.src ! queue ! rtmpsink location='rtmp://live.twitch.tv/app/live_625459812_I8fN8HStRFsCfwf1YrTM9MmDX4d5cK'
