//discuss b09902053 055
#include <bits/stdc++.h>
int **Col,Round;
void ins(int *arr,int player){
    ++arr[0];arr[arr[0]]=player;
}
void pop(int *arr){
    --arr[0];
}

int Count(int **col,int player,int x,int y,int ux,int uy){
    int l=0;
    for(int i=0;i<4;++i){
        if(x+ux*i<1||7<x+ux*i||y+uy*i<1||6<y+uy*i||(y+uy*i<=col[x+ux*i][0]&&col[x+ux*i][y+uy*i]!=player))return 0;
        l+=(y+uy*i<=col[x+ux*i][0]);
    }
    return l;
}
int Score(int **col){
    //if(F)show(col);
    int self_x1y0_2=1,self_x1y0_3=5;
    int self_x1y1_2=1,self_x1y1_3=5;
    int self_x1yi_2=1,self_x1yi_3=5;
    int self_x0y1_2=1,self_x0y1_3=5;
    int op_x1y0_2=-2,op_x1y0_3=-10;
    int op_x1y1_2=-2,op_x1y1_3=-10;
    int op_x1yi_2=-2,op_x1yi_3=-10;
    int op_x0y1_2=-2,op_x0y1_3=-10;
    int self_key[10][10],op_key[10][10];
    for(int i=1;i<=7;++i)
        for(int j=1;j<=7;++j)self_key[i][j]=op_key[i][j]=0;
    /*if(Round<=5){
        self_x0y1_2*=3;self_x0y1_3*=3;op_x0y1_2*=3;op_x0y1_3*=3;
    }
*/
    //if(F)show(col);
    int l,ans=0,pos1,pos2;
    for(int i=1;i<=4;++i){
        for(int j=1;j<=6;++j){
            l=Count(col,1,i,j,1,0);
            //if(F)printf("i=%d j=%d p=1 x1y0=%d",i,j,l);
            if(l==2){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j)break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j)break;
                    ++pos2;
                }
                if(col[pos1][0]==j-1)ans+=self_x1y0_2*3;
                else ans+=self_x1y0_2;
                if(col[pos2][0]==j-1)ans+=self_x1y0_2*3;
                else ans+=self_x1y0_2;
            }
            else if(l==3){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j)break;
                    ++pos1;
                }
                if(col[pos1][0]==j-1)ans+=self_x1y0_3*3;
                else if((j-col[pos1][0])%2==0)ans+=self_x1y0_3*5;
                else ans+=self_x1y0_3;
                ++self_key[pos1][j];
            }
            //if(F)printf(" ans=%d\n",ans);
            l=Count(col,0,i,j,1,0);
            //if(F)printf("i=%d j=%d p=0 x1y0=%d",i,j,l);
            if(l==2){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j)break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j)break;
                    ++pos2;
                }
                if(col[pos1][0]==j-1)ans+=op_x1y0_2*3;
                else ans+=op_x1y0_2;
                if(col[pos2][0]==j-1)ans+=op_x1y0_2*3;
                else ans+=op_x1y0_2;
            }
            else if(l==3){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j)break;
                    ++pos1;
                }
                if(col[pos1][0]==j-1)ans+=op_x1y0_3*10;
                else if(col[pos1][0]==j-2)ans+=op_x1y0_3*3;
                else ans+=op_x1y0_3;
                ++op_key[pos1][j];
            }
            //if(F)printf(" ans=%d\n",ans);
        }
        //if(F)printf("part 1 %d\n",ans);
        for(int j=1;j<=3;++j){
            l=Count(col,1,i,j,1,1);
            //if(F)printf("i=%d j=%d p=1 x1y1=%d",i,j,l);
            if(l==2){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j+(pos1-i))break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j+(pos2-i))break;
                    ++pos2;
                }
                if(col[pos1][0]==j+(pos1-i)-1)ans+=self_x1y1_2*3;
                else ans+=self_x1y1_2;
                if(col[pos2][0]==j+(pos2-i)-1)ans+=self_x1y1_2*3;
                else ans+=self_x1y1_2;
            }
            else if(l==3){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j+(pos1-i))break;
                    ++pos1;
                }
                if(col[pos1][0]==j+(pos1-i)-1)ans+=self_x1y1_3*3;
                else if((j+(pos1-i)-col[pos1][0])%2==0)ans+=self_x1y1_3*5;
                else ans+=self_x1y1_3;
                ++self_key[pos1][j+pos1-i];
            }
            //if(F)printf(" ans=%d\n",ans);
            l=Count(col,0,i,j,1,1);
            //if(F)printf("i=%d j=%d p=0 x1y1=%d",i,j,l);
            if(l==2){
                    //printf("i=%d j=%d l=2\n",i,j);
                pos1=i;
                while(1){
                    if(col[pos1][0]<j+(pos1-i))break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j+(pos2-i))break;
                    ++pos2;
                }
                if(col[pos1][0]==j+(pos1-i)-1)ans+=op_x1y1_2*3;
                else ans+=op_x1y1_2;
                if(col[pos2][0]==j+(pos2-i)-1)ans+=op_x1y1_2*3;
                else ans+=op_x1y1_2;
            }
            else if(l==3){
                //printf("l=3\n");
                pos1=i;
                while(1){
                    if(col[pos1][0]<j+(pos1-i))break;
                    ++pos1;
                }
                if(col[pos1][0]==j+(pos1-i)-1)ans+=op_x1y1_3*10;
                else if(col[pos1][0]==j+(pos1-i)-2)ans+=op_x1y1_3*3;
                else ans+=op_x1y1_3;
                ++op_key[pos1][j+pos1-i];
            }
            //if(F)printf(" ans=%d\n",ans);
        }
        //if(F)printf("part 2 %d\n",ans);
        for(int j=7;j>=4;--j){
            l=Count(col,1,i,j,1,-1);
            //if(F)printf("i=%d j=%d p=1 x1yi=%d",i,j,l);
            if(l==2){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j-(pos1-i))break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j-(pos2-i))break;
                    ++pos2;
                }
                if(col[pos1][0]==j-(pos1-i)-1)ans+=self_x1yi_2*3;
                else ans+=self_x1yi_2;
                if(col[pos2][0]==j-(pos2-i)-1)ans+=self_x1yi_2*3;
                else ans+=self_x1yi_2;
            }
            else if(l==3){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j-(pos1-i))break;
                    ++pos1;
                }
                if(col[pos1][0]==j-(pos1-i)-1)ans+=self_x1yi_3*3;
                else if((j-(pos1-i)-col[pos1][0])%2==0)ans+=self_x1yi_3*5;
                else ans+=self_x1yi_3;
                ++self_key[pos1][j-pos1+i];
            }
            //if(F)printf(" ans=%d\n",ans);
            l=Count(col,0,i,j,1,-1);
            //if(F)printf("i=%d j=%d p=0 x1yi=%d",i,j,l);
            if(l==2){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j-(pos1-i))break;
                    ++pos1;
                }
                pos2=pos1+1;
                while(1){
                    if(col[pos2][0]<j-(pos2-i))break;
                    ++pos2;
                }
                if(col[pos1][0]==j-(pos1-i)-1)ans+=op_x1yi_2*3;
                else ans+=op_x1yi_2;
                if(col[pos2][0]==j-(pos2-i)-1)ans+=op_x1yi_2*3;
                else ans+=op_x1yi_2;
            }
            else if(l==3){
                pos1=i;
                while(1){
                    if(col[pos1][0]<j-(pos1-i))break;
                    ++pos1;
                }
                if(col[pos1][0]==j-(pos1-i)-1)ans+=op_x1yi_3*10;
                else if(col[pos1][0]==j-(pos1-i)-2)ans+=op_x1yi_3*3;
                else ans+=op_x1yi_3;
                ++op_key[pos1][j-pos1+i];
            }
            //if(F)printf(" ans=%d\n",ans);
        }
        //if(F)printf("part 3 %d\n",ans);
    }
    for(int i=1;i<=7;++i){
        for(int j=1;j<=3&&j<=col[i][0];++j){
            if(col[i][j]==1){
                l=Count(col,1,i,j,0,1);
                if(l==2){
                    ans+=self_x0y1_2*3;
                }
                else if(l==3){
                    ans+=self_x0y1_3*3;
                    ++self_key[i][j+3];
                }
            }
            else{
                l=Count(col,0,i,j,0,1);
                if(l==2){
                    ans+=op_x0y1_2*10;
                }
                else if(l==3){
                    ans+=op_x0y1_3*3;
                    ++op_key[i][j+3];
                }
            }
        }
    }
    for(int i=1;i<=7;++i){
        for(int j=1;j<=6;++j){
            if(self_key[i][j]>0&&self_key[i][j+1]>0)ans+=self_x0y1_3*6;
            if(self_key[i][j]>1)ans-=self_x0y1_3*(self_key[i][j]-1);
            if(op_key[i][j]>0&&op_key[i][j+1]>0)ans+=op_x0y1_3*6;
            if(op_key[i][j]>1)ans-=op_x0y1_3*(op_key[i][j]-1);
        }
    }
    return ans;
}
int Min(int a,int b){
    return a<b?a:b;
}
int Max(int a,int b){
    return a>b?a:b;
}
int Count2(int **col,int player,int x,int y,int ux,int uy){
    int l=0;
    for(int i=0;i<4;++i){
        if(x+ux*i<1||7<x+ux*i||y+uy*i<1||6<y+uy*i||(y+uy*i>col[x+ux*i][0])||col[x+ux*i][y+uy*i]!=player)return 0;
        l+=1;
    }
    return l;
}
int judge2(int **col,int p1,int p2,int x){
    if(Count2(col,col[x][col[x][0]],x,col[x][0],1,0)==4||Count2(col,col[x][col[x][0]],x,col[x][0],1,1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0],0,1)==4||Count2(col,col[x][col[x][0]],x,col[x][0],-1,1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0],-1,0)==4||Count2(col,col[x][col[x][0]],x,col[x][0],-1,-1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0],0,-1)==4||Count2(col,col[x][col[x][0]],x,col[x][0],1,-1)==4
       ||Count2(col,col[x][col[x][0]],x-1,col[x][0],1,0)==4||Count2(col,col[x][col[x][0]],x-1,col[x][0]-1,1,1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]-1,0,1)==4||Count2(col,col[x][col[x][0]],x+1,col[x][0]-1,-1,1)==4
       ||Count2(col,col[x][col[x][0]],x+1,col[x][0],-1,0)==4||Count2(col,col[x][col[x][0]],x+1,col[x][0]+1,-1,-1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]+1,0,-1)==4||Count2(col,col[x][col[x][0]],x-1,col[x][0]+1,1,-1)==4
       ||Count2(col,col[x][col[x][0]],x-2,col[x][0],1,0)==4||Count2(col,col[x][col[x][0]],x-2,col[x][0]-2,1,1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]-2,0,1)==4||Count2(col,col[x][col[x][0]],x+2,col[x][0]-2,-1,1)==4
       ||Count2(col,col[x][col[x][0]],x+2,col[x][0],-1,0)==4||Count2(col,col[x][col[x][0]],x+2,col[x][0]+2,-1,-1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]+2,0,-1)==4||Count2(col,col[x][col[x][0]],x-2,col[x][0]+2,1,-1)==4
       ||Count2(col,col[x][col[x][0]],x-3,col[x][0],1,0)==4||Count2(col,col[x][col[x][0]],x-3,col[x][0]-3,1,1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]-3,0,1)==4||Count2(col,col[x][col[x][0]],x+3,col[x][0]-3,-1,1)==4
       ||Count2(col,col[x][col[x][0]],x+3,col[x][0],-1,0)==4||Count2(col,col[x][col[x][0]],x+3,col[x][0]+3,-1,-1)==4
       ||Count2(col,col[x][col[x][0]],x,col[x][0]+3,0,-1)==4||Count2(col,col[x][col[x][0]],x-3,col[x][0]+3,1,-1)==4)
        return col[x][col[x][0]];
    //printf("return -1\n");
    return -1;
}
int decide(int yp_move){//1 means self , 0 means op
    int result;
    if(yp_move==-1){
        Round=0;
        Col=(int**)malloc(sizeof(int*)*20);
        for(int i=1;i<=15;++i){
            Col[i]=(int*)malloc(sizeof(int)*20);
            for(int j=0;j<=6;++j)Col[i][j]=0;
        }
    }
    else{
        ++Round;
        ins(Col[yp_move+1],0);
        if(judge2(Col,1,2,yp_move+1)!=-1){
            printf("玩家獲勝\n");exit(0);
        }
    }
    if(Round<2){
        if(Round==0){
            ins(Col[4],1);return 3;
        }
        else if(Round==1){
            if(yp_move==1||yp_move==5){
                ins(Col[yp_move+1],1);return yp_move;
            }
            if(yp_move==2||yp_move==4){
                ins(Col[-2*yp_move+10],1);return -2*yp_move+9;
            }
            else
                ins(Col[4],1);return 3;
        }
    }
    int flag=1,score[8],win,x,y,z,fx,fy,fz;
    for(int i=1;i<=7;++i){
        if(Col[i][0]==6)
            score[i]=-1000000000;
        else{
            score[i]=100000;
            flag=0;
        }
    }
    if(flag)return -1;
    for(int i=1;i<=7;++i){
        if(Col[i][0]==6){
            score[i]=-1000000000;
            continue;
        }
        ins(Col[i],1);
        if(judge2(Col,1,0,i)==1){
            //pop(Col[i]);
            return i-1;
        }
        for(int j=1;j<=7;++j){
            if(Col[j][0]==6)continue;
            ins(Col[j],0);
            if(judge2(Col,1,0,j)==0){
                score[i]=-400000;
                pop(Col[j]);
                break;
            }
            x=-300000;fx=1;
            for(int k=1;k<=7;++k){
                if(Col[k][0]>6)continue;
                fx=0;
                ins(Col[k],1);
                if(judge2(Col,1,0,k)==1){
                    pop(Col[k]);
                    x=300000;
                    break;
                }
                y=200000;fy=1;
                for(int l=1;l<=7;++l){
                    if(Col[l][0]>6)continue;
                    fy=0;
                    ins(Col[l],0);
                    if(judge2(Col,1,0,l)==0){
                        y=-200000;
                        pop(Col[l]);
                        break;
                    }
                    z=-100000;fz=1;
                    for(int m=1;m<=7;++m){
                        if(Col[m][0]>6)continue;
                        fz=0;
                        ins(Col[m],1);
                        if(judge2(Col,1,0,m)==0){
                            z=100000;
                            pop(Col[l]);
                            break;
                        }
                        z=Max(z,Score(Col));
                        pop(Col[m]);
                    }
                    if(fz)z=0;
                    y=Min(y,z);
                    pop(Col[l]);
                }
                if(fy)y=0;
                x=Max(x,y);
                pop(Col[k]);
            }
            if(fx)x=0;
            score[i]=Min(score[i],x);
            pop(Col[j]);
        }
        pop(Col[i]);
    }
    int m=1;
    /*if(Round<=4){
        score[3]+=20;score[4]+=21;score[5]+=20;
    }*/
    score[4]+=14;
    for(int i=2;i<=7;++i)
        if(score[i]>score[m])m=i;
    //cout<<score[1]<<' '<<score[2]<<' '<<score[3]<<' '<<score[4]<<' '<<score[5]<<' '<<score[6]<<' '<<score[7]<<'\n';
    ins(Col[m],1);
    return m-1;
}
void show(){
    printf("玩家:X\n電腦:O\n");
    printf("********************\n");
    for(int i=6;i>=1;--i){
        printf("|");
        for(int j=1;j<=7;++j){
            if(i<=Col[j][0])printf("%c",Col[j][i]==1?'O':'X');
            else printf(" ");
            printf("|");
        }
        printf("\n");
        //printf("\n - - - - - - - \n");
    }
    printf(" 1 2 3 4 5 6 7 \n********************\n");
}
int main(){
    int x=4;
    decide(-1);
    while(1){
        show();
        while(1){
            printf("下在哪一直行?:");
            scanf("%d",&x);
            if(1<=x&&x<=7&&Col[x][0]<6)break;
        }
        if(judge2(Col,1,2,decide(x-1)+1)!=-1){
            show();
            printf("電腦獲勝\n");exit(0);
        }
    }
    return 0;
}
