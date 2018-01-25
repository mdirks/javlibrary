#ifndef KATALOGGUIMODE_H
#define KATALOGGUIMODE_H

#include <guimode.h>
#include <pobjecticonview.h>

#include <QSplitter>
#include <QtMultimediaWidgets/QVideoWidget>

class KatalogGuiMode : public GuiMode
{
Q_OBJECT
public:
    KatalogGuiMode();

    void setupMode();

public slots:
    void resetActress();

private:
    PObjectIconView *aview, *mview;
    QSplitter *sp;
    RpListProvider *film_list;
    QVideoWidget *videow;
    RepositoryProperty *rp_film;
};

#endif // KATALOGGUIMODE_H
