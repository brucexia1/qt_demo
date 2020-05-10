#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <stdint.h>
#include <QMetaType>

class MyImage
{
public:
    MyImage();

    void setSthrNo(uint8_t sthr);
    uint8_t getSthrNo();

private:
    uint8_t m_bSthr;
    uint8_t rsv[3];
    uint8_t img[2048];
};

Q_DECLARE_METATYPE(MyImage);

#endif // MYIMAGE_H
