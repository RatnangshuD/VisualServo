#include <visp3/core/vpConfig.h>
#ifdef VISP_HAVE_MODULE_SENSOR
#include <visp3/sensor/vp1394CMUGrabber.h>
#include <visp3/sensor/vp1394TwoGrabber.h>
#endif
#include <visp3/blob/vpDot2.h>
#include <visp3/gui/vpDisplayGDI.h>
#include <visp3/gui/vpDisplayOpenCV.h>
#include <visp3/gui/vpDisplayX.h>

#define VISP_HAVE_OPENCV

int main()
{
#if (defined(VISP_HAVE_DC1394) || defined(VISP_HAVE_CMU1394) || (VISP_HAVE_OPENCV_VERSION >= 0x020100)) &&             \
    (defined(VISP_HAVE_X11) || defined(VISP_HAVE_GDI) || defined(VISP_HAVE_OPENCV))
  vpImage<unsigned char> I; // Create a gray level image container
 

  cv::VideoCapture g(0); // open the default camera
  if (!g.isOpened()) {   // check if we succeeded
    std::cout << "Failed to open the camera" << std::endl;
    return -1;
  }
  cv::Mat frame;
  g >> frame; // get a new frame from camera
  vpImageConvert::convert(frame, I);

 
#if defined(VISP_HAVE_X11)
  vpDisplayX d(I, 0, 0, "Camera view");
#elif defined(VISP_HAVE_GDI)
  vpDisplayGDI d(I, 0, 0, "Camera view");
#elif defined(VISP_HAVE_OPENCV)
  vpDisplayOpenCV d(I, 0, 0, "Camera view");
#endif
 
  vpDot2 blob;
  blob.setGraphics(true);
  blob.setGraphicsThickness(2);
 
  vpImagePoint germ;
  bool init_done = false;
 
  while (1) {
    try {

      g >> frame;
      vpImageConvert::convert(frame, I);

      vpDisplay::display(I);
 
      if (!init_done) {
        vpDisplay::displayText(I, vpImagePoint(10, 10), "Click in the blob to initialize the tracker", vpColor::yellow);
        if (vpDisplay::getClick(I, germ, false)) {
          blob.initTracking(I, germ);
          init_done = true;
        }
      } else {
        blob.track(I);
      }
 
      vpDisplay::flush(I);
    } catch (...) {
      init_done = false;
    }
  }
#endif
}
