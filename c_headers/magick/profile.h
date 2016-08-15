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

  ImageMagick image profile methods.
*/
#ifndef _MAGICK_PROFILE_H
#define _MAGICK_PROFILE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "magick/string_.h"

extern MagickExport char
  *GetNextImageProfile(const Image *);

extern MagickExport MagickBooleanType
  CloneImageProfiles(Image *,const Image *),
  ProfileImage(Image *,const char *,const void *,const unsigned long,
    const MagickBooleanType),
  RemoveImageProfile(Image *,const char *),
  SetImageProfile(Image *,const char *,const StringInfo *);

extern MagickExport StringInfo
  *GetImageProfile(const Image *,const char *);

extern MagickExport void
  DestroyImageProfiles(Image *),
  ResetImageProfileIterator(const Image *);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif 
#endif
