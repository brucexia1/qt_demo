#include "myimage.h"

MyImage::MyImage()
{

}

void MyImage::setSthrNo(uint8_t sthr)
{
    m_bSthr = sthr;
}
uint8_t MyImage::getSthrNo()
{
    return m_bSthr;
}
