


namespace flash {
namespace media {


        int VideoStreamSettings::width()      ;

        int VideoStreamSettings::height()      ;

        float VideoStreamSettings::fps()         ;

        int VideoStreamSettings::quality()      ;

        int VideoStreamSettings::bandwidth()      ;

        int VideoStreamSettings::keyFrameInterval()      ;

        std::string VideoStreamSettings::codec()         ;

        void VideoStreamSettings::setMode(int width, int height, float fps)       ;

        VideoStreamSettings::VideoStreamSettings();

        void VideoStreamSettings::setQuality(int bandwidth, int quality)       ;

        void VideoStreamSettings::setKeyFrameInterval(int keyFrameInterval)       ;
}
}

