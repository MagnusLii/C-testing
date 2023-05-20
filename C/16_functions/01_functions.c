#include <stdio.h>

int main(){

    for (size_t i = 1; i < 4; i++)
    {
        text();
    }
    
    return 0;
}


// functions are traditionally placed below main().

void text(){
    printf("\nLorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
            "Nam at condimentum ante. Nullam et sapien sed lacus laoreet tempor ac vitae lacus.\n"
            "Phasellus quis vestibulum sapien, ut feugiat justo. Nulla et efficitur dui. Suspendisse potenti.\n"
            "Nullam condimentum dictum enim, eget ultricies turpis. Pellentesque ligula nisi,\n"
            "tempor quis risus ut, maximus auctor elit. Mauris ac molestie sem, ac tincidunt ante.\n"
            "Nullam ultricies, augue at lobortis tempus, sapien quam lobortis turpis,\n"
            "sit amet dictum leo erat a magna.\n");
}