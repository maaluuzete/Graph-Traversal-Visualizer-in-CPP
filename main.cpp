#include <SDL3/SDL.h>
#include <cmath>
#include <vector>
#include "graph.h"
using namespace std;

int w=800,h=600,r=12;

enum mode{addn,adde,sel};

int get_node(const graph& g,int mx,int my){
    for(auto &n:g.nodes()){
        float dx=mx-n.x;
        float dy=my-n.y;
        if(dx*dx+dy*dy<=r*r){
            return n.id;
        }
    }
    return -1;
}

void draw_circ(SDL_Renderer* rd,int x,int y,int rr){
    for(int i=-rr;i<=rr;i++){
        for(int j=-rr;j<=rr;j++){
            if(i*i+j*j<=rr*rr){
                SDL_RenderPoint(rd,x+i,y+j);
            }
        }
    }
}

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win=SDL_CreateWindow("graph",w,h,0);
    SDL_Renderer* rd=SDL_CreateRenderer(win,NULL);
    graph g;
    g.load("saved_graph.txt");
    mode md=addn;
    int seln=-1,st=-1;
    vector<int> ord;
    int it=0;
    Uint32 lst=0;
    bool run=1;
    while(run){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_EVENT_QUIT){
                run=0;
            }
            if(e.type==SDL_EVENT_KEY_DOWN){
                if(e.key.key=='n'){
                     md=addn;
                }
                if(e.key.key=='e'){
                     md=adde;
                }
                if(e.key.key=='s'){
                     md=sel;
                }
                if(e.key.key=='b'&&st!=-1){
                    ord=g.bfs(st); it=0;
                }
                if(e.key.key=='d'&&st!=-1){
                    ord=g.dfs(st); it=0;
                }
                if(e.key.key=='c'){
                    ord.clear(); it=0;
                }
                if(e.key.key=='w')
                    g.save("saved_graph.txt");
            }

            if(e.type==SDL_EVENT_MOUSE_BUTTON_DOWN){
                int mx=e.button.x,my=e.button.y;

                if(md==addn){
                    g.add_node(mx,my);
                }else if(md==adde){
                    int id=get_node(g,mx,my);
                    if(id!=-1){
                        if(seln==-1){
                            seln=id;
                        }else{
                            g.add_edge(seln,id);
                            seln=-1;
                        }
                    }
                }else if(md==sel){
                    st=get_node(g,mx,my);
                }
            }
        }

        if(!ord.empty()&&it<ord.size()){
            if(SDL_GetTicks()-lst>500){
                it++;
                lst=SDL_GetTicks();
            }
        }

        SDL_SetRenderDrawColor(rd,20,20,20,255);
        SDL_RenderClear(rd);
        SDL_SetRenderDrawColor(rd,200,200,200,255);
        for(auto &e:g.edges()){
            auto &a=g.nodes()[e.u];
            auto &b=g.nodes()[e.v];
            SDL_RenderLine(rd,a.x,a.y,b.x,b.y);
        }
        for(auto &n:g.nodes()){
            bool vis=0;
            for(int i=0;i<it;i++){
                if(ord[i]==n.id){
                    vis=1;
                }
            }
            if(n.id==st){
                SDL_SetRenderDrawColor(rd,0,200,0,255);
            }else if(vis){
                SDL_SetRenderDrawColor(rd,200,50,50,255);
            }else{
                SDL_SetRenderDrawColor(rd,100,100,255,255);
            }
            draw_circ(rd,n.x,n.y,r);
        }
        SDL_RenderPresent(rd);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(rd);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
