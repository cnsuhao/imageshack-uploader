/*
Copyright (c) 2009, ImageShack Corp.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
* Neither the name of the ImageShack nor the names of its contributors may be
  used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef IMAGEINFOWIDGET_H
#define IMAGEINFOWIDGET_H

#include <QtGui/QWidget>
#include <QMap>
#include <QSharedPointer>
#include "media.h"

namespace Ui {
    class ImageInfoWidget;
}

class ImageInfoWidget : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(ImageInfoWidget)
public:
    explicit ImageInfoWidget(QWidget *parent = 0);
    virtual ~ImageInfoWidget();
    void enable();
    void disable();
    void reset();
    void setMedia(QSharedPointer<Media>);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ImageInfoWidget *m_ui;
    QSharedPointer<Media> media;
    QMap<QString, int> items;
    QString cleanup(QString);
    bool loggedIn;

private slots:
    void setResize(int);
    void setRemoveSize(int);
    void thumbnailClicked();
    void tagsUpdated();
    void privacyUpdated();
    void batchPrivacy(bool);
    void loginStatusReceiver(int);
    void resizeAll();

signals:
    void resizeAllImagesTo(QString);
};

#endif // IMAGEINFOWIDGET_H
