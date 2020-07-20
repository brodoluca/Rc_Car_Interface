#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "backend.h"
#include "localserver.h"
class thread : public QThread
{

    Q_PROPERTY(int center_obj READ center_obj NOTIFY obj_centerChanged)


public:
    thread();
    void run();
backend *back;


    char center;
    int center_obj(){
        return l;

    }

    void set_center_obj(char value){
        if(center != value) {
            if(center == 'c'){

                   l=0;
            }else{

            }
            obj_centerChanged();
        }

    }

    int l;

protected:



signals:
    void obj_centerChanged();
private:

};





#endif // THREAD_H
