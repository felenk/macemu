/*
 *  MacOSX_sound_if.h
 *  BasiliskII
 *
 *  Copyright 2006 Daniel Sumorok. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef MACOSX_SOUND_IF
#define MACOSX_SOUND_IF

typedef int (*audioCallback)(void);

class AudioBackEnd;

class OSXsoundOutput {
 private:
  static void getMoreSamples(void *arg);

  AudioBackEnd *player;
  audioCallback callback;
 public:
  OSXsoundOutput();
  ~OSXsoundOutput();
  int start(int bitsPerSample, int numChannels, int sampleRate);
  int stop();
  int putBuffer(void *buffer, int numSamples);
  void setCallback(audioCallback fn);
  unsigned int bufferSizeFrames();
  int sendAudioBuffer(void *buffer, int numFrames);
};

#endif
