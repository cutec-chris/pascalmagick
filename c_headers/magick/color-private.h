/*
  Copyright 1999-2005 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  ImageMagick image color methods.
*/
#ifndef _MAGICK_COLOR_PRIVATE_H
#define _MAGICK_COLOR_PRIVATE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include <magick/image.h>
#include <magick/color.h>
#include <magick/exception-private.h>

static inline MagickBooleanType ColorMatch(const PixelPacket *p,
  const PixelPacket *q)
{
  MagickBooleanType
    match;

  match=(p->red == q->red) && (p->green == q->green) && (p->blue == q->blue) ?
    MagickTrue : MagickFalse;
  return(match);
}

static inline IndexPacket ConstrainColormapIndex(Image *image,
  const unsigned long index)
{
  if (index >= image->colors)
    {
      (void) ThrowMagickException(&image->exception,GetMagickModule(),
        CorruptImageError,"InvalidColormapIndex","`%s'",image->filename);
      return(0);
    }
  return((IndexPacket) index);
}

static inline MagickBooleanType IsGray(const PixelPacket *pixel)
{
  MagickBooleanType
    gray;

  gray=(pixel->red == pixel->green) && (pixel->green == pixel->blue) ?
    MagickTrue : MagickFalse;
  return(gray);
}

static inline MagickBooleanType IsMagickColorEqual(const MagickPixelPacket *p,
  const MagickPixelPacket *q)
{
  if (p->red != q->red)
    return(MagickFalse);
  if (p->green != q->green)
    return(MagickFalse);
  if (p->blue != q->blue)
    return(MagickFalse);
  if ((p->matte != MagickFalse) && (p->opacity != q->opacity))
    return(MagickFalse);
  if ((p->colorspace == CMYKColorspace) && (p->index != q->index))
    return(MagickFalse);
  return(MagickTrue);
}

static inline MagickBooleanType IsMagickGray(const MagickPixelPacket *pixel)
{
  MagickBooleanType
    gray;

  gray=(pixel->red == pixel->green) && (pixel->green == pixel->blue) ?
    MagickTrue : MagickFalse;
  return(gray);
}

static inline MagickRealType MagickPixelIntensity(
  const MagickPixelPacket *pixel)
{
  MagickRealType
    intensity;

  intensity=0.299*pixel->red+0.587*pixel->green+0.114*pixel->blue;
  return(intensity);
}

static inline Quantum MagickPixelIntensityToQuantum(
  const MagickPixelPacket *pixel)
{
  return((Quantum) (MagickPixelIntensity(pixel)+0.5));
}

static inline MagickRealType PixelIntensity(const PixelPacket *pixel)
{
  MagickRealType
    intensity;

  intensity=(MagickRealType) (0.299*pixel->red+0.587*pixel->green+
    0.114*pixel->blue);
  return(intensity);
}

static inline Quantum PixelIntensityToQuantum(const PixelPacket *pixel)
{
  return((Quantum) (PixelIntensity(pixel)+0.5));
}

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
