// Copyright 2013 Velodyne Acoustics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef __vvSelectFramesDialog_h
#define __vvSelectFramesDialog_h

#include <QDialog>

#include "vvConfigure.h"

class VelodyneHDLPlugin_EXPORT vvSelectFramesDialog : public QDialog
{
  Q_OBJECT
  Q_PROPERTY(int frameMode READ frameMode WRITE setFrameMode)
  Q_PROPERTY(int frameStart READ frameStart WRITE setFrameStart)
  Q_PROPERTY(int frameStop READ frameStop WRITE setFrameStop)
  Q_PROPERTY(int frameStride READ frameStride WRITE setFrameStride)
  Q_PROPERTY(int frameMinimum WRITE setFrameMinimum)
  Q_PROPERTY(int frameMaximum WRITE setFrameMaximum)
  Q_PROPERTY(bool frameStrideVisibility WRITE setFrameStrideVisibility)
  Q_ENUMS(FrameMode)

public:
  vvSelectFramesDialog(QWidget *p=0);
  virtual ~vvSelectFramesDialog();

  enum FrameMode
    {
    CURRENT_FRAME = 0,
    ALL_FRAMES,
    FRAME_RANGE
    };

  int frameMode() const;
  int frameStart() const;
  int frameStop() const;
  int frameStride() const;

public slots:
  virtual void accept();

  void setFrameMode(int frameMode);
  void setFrameStart(int frameStart);
  void setFrameStop(int frameStop);
  void setFrameStride(int frameStride);

  void setFrameMinimum(int frameMin);
  void setFrameMaximum(int frameMax);

  void setFrameStrideVisibility(bool visible);

  void saveState();
  void restoreState();

private:
  class pqInternal;
  pqInternal* Internal;

  Q_DISABLE_COPY(vvSelectFramesDialog);
};

#endif
