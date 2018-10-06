#include "World.h"


World::World()
{
    //ctor
}

World::initalize(char level[])
{
    int i,k;
    FILE * fp;
    fp = fopen(level,"r");
    fscanf(fp,"%d %d",&width,&height);
    tiles = (int **) malloc(height*width*sizeof(int*));
    for(i=0;i<width;i++) tiles[i]=(int *)malloc(height*sizeof(int));
    for(i=0;i<height;i++) for(k=0;k<width;k++) fscanf(fp,"%d ",&tiles[k][i]);
    fclose(fp);
}
World::~World()
{
    free(tiles);
    //dtor
}
