#ifndef FILMITEMTEMPLATE_H
#define FILMITEMTEMPLATE_H

#include <pobjecticonviewitem.h>
#include <datamodel/film.h>

class FilmItemTemplate : public PObjectIconViewItemTemplate
{
Q_OBJECT

public:
    FilmItemTemplate();
    FilmItemTemplate(QListWidget *iv);

    PObjectIconViewItemTemplate* getInstanceFor(QListWidget *lv);
    //void setListWidget(QListWidget *iv);
    PObjectIconViewItemBase* createItem(PObject *o);

    void activateItem();

public slots:
    void resizeIcons();

private:
    QListWidget *iv;
    film *fm;
};

class FilmItem : public PObjectIconViewItemBase
{
public:
    FilmItem(PObject *o, QListWidget *iv);

    void activateItem();

};

#endif // FILMITEMTEMPLATE_H
