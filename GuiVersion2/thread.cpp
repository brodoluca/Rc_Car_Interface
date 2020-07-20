#include "thread.h"

thread::thread()
{
    back = new backend;

}
void thread::run()
{
    while (1) {

        center = back->server->get_center();
        if(center =='c'){
            back->get_object_write(1);
        }else if(center =='l'){
            back->get_object_write_left(1);
        }else if(center == 'r'){
             back->get_object_write_right(1);
        }else{
            back->get_object_write_right(0);
            back->get_object_write(0);
            back->get_object_write_left(0);
        }
        //printf("LUUL THREADS   %c\n", center);
        //usleep(500);
        sleep(1);

    }

}


