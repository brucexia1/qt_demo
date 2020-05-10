#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <stdint.h>
#include <QMetaType>

class MyImage
{
public:
    MyImage();

private:
    uint8_t img[2048];
};

Q_DECLARE_METATYPE(MyImage);

#endif // MYIMAGE_H
