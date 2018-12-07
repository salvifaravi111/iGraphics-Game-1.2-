/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/

int z = 1, birdx = 64, birdy = 300,ball = 0, ballx = 32, score = 0, score2 = 0,cov=0,bally=0,ballmove=0;
int life = 3, enemyx=1300-200, enemyy=300,invisible=0,en=0,menu=0,scorereal=0,mode=0,k=0,len=0,gover=0,menuchange=0;
int invisible2=0,invisible3=0,invisible4=0,invisible5=0,invisible6=0;
int cloudx = 400, cloudy = 170, cloud2x = 200, cloud2y = 300, cloud3x = 600, cloud3y = 380, cloud4x = 800, cloud4y = 200, cloud5x = 1000, cloud5y = 400, cloud6x = 1200, cloud6y = 150;

int cloud8x = 300, cloud8y = 400, cloud9x = 500, cloud9y = 100, cloud10x = 650, cloud10y = 300, cloud11x = 850, cloud11y = 200, cloud12x = 1000, cloud12y = 400, cloud130x = 1250, cloud130y = 100, cloud140x = 100, cloud140y = 200,invisible8=0, invisible9 = 0, invisible10 = 0, invisible11 = 0, invisible12 = 0, invisible130 = 0, invisible140 = 0;

int cloud13x = 250, cloud13y = 400, invisible13 = 0;
int cloud14x = 370, cloud14y = 170, invisible14 = 0;
int cloud15x = 570, cloud15y = 370, invisible15 = 0;
int cloud16x = 720, cloud16y = 90, invisible16 = 0;
int cloud17x = 870, cloud17y = 300, invisible17 = 0;
int cloud18x = 1030, cloud18y = 450, invisible18 = 0;
int cloud19x = 1200, cloud19y = 150, invisible19 = 0;
int cloud20x = 140, cloud20y = 130, invisible20 = 0;
int cloud21x = 310, cloud21y = 350, invisible21 = 0;
int cloud22x = 500, cloud22y = 150, invisible22 = 0;
int cloud23x = 640, cloud23y = 380, invisible23 = 0;
int cloud24x = 790, cloud24y = 100, invisible24 = 0;
int cloud25x = 940, cloud25y = 280, invisible25 = 0;
int cloud26x = 1010, cloud26y = 470, invisible26 = 0;
int cloud27x = 1200, cloud27y = 120, invisible27 = 0;
int flag = 0, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0, flag7 = 0, flag8 = 0, flag9 = 0, flag10 = 0, flag11 = 0, flag12 = 0, flag13 = 0, flag14 = 0, flag15 = 0;
int flag16 = 0, flag17 = 0, flag18 = 0, flag19 = 0, flag20 = 0, flag21 = 0, flag22 = 0, flag23 = 0, flag24 = 0, flag25 = 0, flag26 = 0, flag27 = 0, flag28 = 0;
int z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0, z9 = 0, z10 = 0, z11 = 0, z12 = 0, z130 = 0, z140 = 0, z13 = 0, z14 = 0;
int z15 = 0, z16 = 0, z17 = 0, z18 = 0, z19 = 0, z20 = 0, z21 = 0, z22 = 0, z23 = 0, z24 = 0, z25 = 0, z26 = 0, z27 = 0;
char score1[100],name[100],sco[10];
int n1 = 0, s, j,t,t1,f1=0,t2,t3;
FILE* fp;
int bossz = 1;
int bossx = 1300 - 256;
int bossy = 300;
int firex = 0;
int move = 0;
int firem = 0;
int firey = 0;
int bosslife = 6,bossl=0, delay=0,story=0,delay2=0;




struct ns{
	char name[100];
	int score;
}temp;
struct ns info[100];


void birdmove(){
	if (menuchange != 4){
		birdx += 2;
		if (birdx >= 1300 - 64){
			if (menuchange<4)
			menuchange++;
			birdx = 64;


		}
	}
	if (menuchange == 0){
		//Lifeloss//
		if (((birdx + 64 == cloudx  && ((birdy >= cloudy && birdy <= cloudy + 64) || (birdy+64<=cloudy+64 && birdy+64>=cloudy))) || (birdy+64>=cloudy && birdy+64<=cloudy+64 && (birdx>=cloudx && birdx+64<=cloudx+64)))&& flag==0){
			life--;
			flag = 1;
		}
		//scoreplus//
		if (((birdx + 64 == cloudx &&  cloudy+80>=birdy &&  cloudy + 80 + 32<=birdy+64) || (birdy<=cloudy+80+32 && birdy>=cloudy+80  && cloudx>=birdx && cloudx+32<=birdx+64)) && invisible == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible = 1;
		}

		if (((birdx + 64 == cloud2x && ((birdy >= cloud2y && birdy <= cloud2y + 64) || (birdy + 64 <= cloud2y + 64 && birdy + 64 >= cloud2y))) || (birdy + 64 >= cloud2y && birdy + 64 <= cloud2y + 64 && (birdx >= cloud2x && birdx + 64 <= cloud2x + 64)))&& flag1==0){
			life--;
			flag1 = 1;
		}
		if (((birdx + 64 == cloud2x &&  cloud2y + 80 >= birdy &&  cloud2y + 80 + 32 <= birdy + 64) || (birdy <= cloud2y + 80 + 32 && birdy >= cloud2y + 80 && cloud2x >= birdx && cloud2x + 32 <= birdx + 64)) && invisible2 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible2 = 1;
		}

		if (((birdx + 64 == cloud3x && ((birdy >= cloud3y && birdy <= cloud3y + 64) || (birdy + 64 <= cloud3y + 64 && birdy + 64 >= cloud3y))) || (birdy + 64 >= cloud3y && birdy + 64 <= cloud3y + 64 && (birdx >= cloud3x && birdx + 64 <= cloud3x + 64)))&& flag2==0){
			life--;
			flag2 = 1;
		}
		if (((birdx + 64 == cloud3x &&  cloud3y + 80 >= birdy &&  cloud3y + 80 + 32 <= birdy + 64) || (birdy <= cloud3y + 80 + 32 && birdy >= cloud3y + 80 && cloud3x >= birdx && cloud3x + 32 <= birdx + 64)) && invisible3 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible3 = 1;
		}
		if (((birdx + 64 == cloud4x && ((birdy >= cloud4y && birdy <= cloud4y + 64) || (birdy + 64 <= cloud4y + 64 && birdy + 64 >= cloud4y))) || (birdy + 64 >= cloud4y && birdy + 64 <= cloud4y + 64 && (birdx >= cloud4x && birdx + 64 <= cloud4x + 64)))&& flag3==0){
			life--;
			flag3 = 1;
		}
		if (((birdx + 64 == cloud4x &&  cloud4y + 80 >= birdy &&  cloud4y + 80 + 32 <= birdy + 64) || (birdy <= cloud4y + 80 + 32 && birdy >= cloud4y + 80 && cloud4x >= birdx && cloud4x + 32 <= birdx + 64)) && invisible4 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible4 = 1;
		}
		if (((birdx + 64 == cloud5x && ((birdy >= cloud5y && birdy <= cloud5y + 64) || (birdy + 64 <= cloud5y + 64 && birdy + 64 >= cloud5y))) || (birdy + 64 >= cloud5y && birdy + 64 <= cloud5y + 64 && (birdx >= cloud5x && birdx + 64 <= cloud5x + 64)))&& flag4==0){
			life--;
			flag4 = 1;
		}
		if (((birdx + 64 == cloud5x &&  cloud5y + 80 >= birdy &&  cloud5y + 80 + 32 <= birdy + 64) || (birdy <= cloud5y + 80 + 32 && birdy >= cloud5y + 80 && cloud5x >= birdx && cloud5x + 32 <= birdx + 64)) && invisible5 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible5 = 1;
		}
		if (((birdx + 64 == cloud6x && ((birdy >= cloud6y && birdy <= cloud6y + 64) || (birdy + 64 <= cloud6y + 64 && birdy + 64 >= cloud6y))) || (birdy + 64 >= cloud6y && birdy + 64 <= cloud6y + 64 && (birdx >= cloud6x && birdx + 64 <= cloud6x + 64))) && flag5==0){
			life--;
			flag5 = 1;
		}
		if (((birdx + 64 == cloud6x &&  cloud6y + 80 >= birdy &&  cloud6y + 80 + 32 <= birdy + 64) || (birdy <= cloud6y + 80 + 32 && birdy >= cloud6y + 80 && cloud6x >= birdx && cloud6x + 32 <= birdx + 64)) && invisible6 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible6 = 1;
		}

		if (birdx + 64 == enemyx && birdy >= enemyy && birdy <= enemyy + 128 && en == 0)
			life = 0;
	}


	if (menuchange == 1){
	

		if (((birdx + 64 == cloud8x && ((birdy >= cloud8y && birdy <= cloud8y + 64) || (birdy + 64 <= cloud8y + 64 && birdy + 64 >= cloud8y))) || (birdy + 64 >= cloud8y && birdy + 64 <= cloud8y + 64 && (birdx >= cloud8x && birdx + 64 <= cloud8x + 64)))&& flag6==0){
			life--;
			flag6 = 1;
		}
		if (((birdx + 64 == cloud8x &&  cloud8y + 80 >= birdy &&  cloud8y + 80 + 32 <= birdy + 64) || (birdy <= cloud8y + 80 + 32 && birdy >= cloud8y + 80 && cloud8x >= birdx && cloud8x + 32 <= birdx + 64)) && invisible8 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible8 = 1;
		}

		if (((birdx + 64 == cloud9x && ((birdy >= cloud9y && birdy <= cloud9y + 64) || (birdy + 64 <= cloud9y + 64 && birdy + 64 >= cloud9y))) || (birdy + 64 >= cloud9y && birdy + 64 <= cloud9y + 64 && (birdx >= cloud9x && birdx + 64 <= cloud9x + 64)))&& flag7==0){
			life--;
			flag7 = 1;
		}
		if (((birdx + 64 == cloud9x &&  cloud9y + 80 >= birdy &&  cloud9y + 80 + 32 <= birdy + 64) || (birdy <= cloud9y + 80 + 32 && birdy >= cloud9y + 80 && cloud9x >= birdx && cloud9x + 32 <= birdx + 64)) && invisible9 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible9 = 1;
		}

		if (((birdx + 64 == cloud10x && ((birdy >= cloud10y && birdy <= cloud10y + 64) || (birdy + 64 <= cloud10y + 64 && birdy + 64 >= cloud10y))) || (birdy + 64 >= cloud10y && birdy + 64 <= cloud10y + 64 && (birdx >= cloud10x && birdx + 64 <= cloud10x + 64)))&& flag8==0){
			life--;
			flag8 = 1;
		}
		if (((birdx + 64 == cloud10x &&  cloud10y + 80 >= birdy &&  cloud10y + 80 + 32 <= birdy + 64) || (birdy <= cloud10y + 80 + 32 && birdy >= cloud10y + 80 && cloud10x >= birdx && cloud10x + 32 <= birdx + 64)) && invisible10 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible10 = 1;
		}
		if (((birdx + 64 == cloud11x && ((birdy >= cloud11y && birdy <= cloud11y + 64) || (birdy + 64 <= cloud11y + 64 && birdy + 64 >= cloud11y))) || (birdy + 64 >= cloud11y && birdy + 64 <= cloud11y + 64 && (birdx >= cloud11x && birdx + 64 <= cloud11x + 64)))&& flag9==0){
			life--;
			flag9 = 1;
		}
		if (((birdx + 64 == cloud11x &&  cloud11y + 80 >= birdy &&  cloud11y + 80 + 32 <= birdy + 64) || (birdy <= cloud11y + 80 + 32 && birdy >= cloud11y + 80 && cloud11x >= birdx && cloud11x + 32 <= birdx + 64)) && invisible11 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible11 = 1;
		}
		if (((birdx + 64 == cloud12x && ((birdy >= cloud12y && birdy <= cloud12y + 64) || (birdy + 64 <= cloud12y + 64 && birdy + 64 >= cloud12y))) || (birdy + 64 >= cloud12y && birdy + 64 <= cloud12y + 64 && (birdx >= cloud12x && birdx + 64 <= cloud12x + 64)))&& flag10==0){
			life--;
			flag10 = 1;
		}
		if (((birdx + 64 == cloud12x &&  cloud12y + 80 >= birdy &&  cloud12y + 80 + 32 <= birdy + 64) || (birdy <= cloud12y + 80 + 32 && birdy >= cloud12y + 80 && cloud12x >= birdx && cloud12x + 32 <= birdx + 64)) && invisible12 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible12 = 1;
		}
		if (((birdx + 64 == cloud130x && ((birdy >= cloud130y && birdy <= cloud130y + 64) || (birdy + 64 <= cloud130y + 64 && birdy + 64 >= cloud130y))) || (birdy + 64 >= cloud130y && birdy + 64 <= cloud130y + 64 && (birdx >= cloud130x && birdx + 64 <= cloud130x + 64)))&& flag11==0){
			life--;
			flag11 = 1;
		}
		if (((birdx + 64 == cloud130x &&  cloud130y + 80 >= birdy &&  cloud130y + 80 + 32 <= birdy + 64) || (birdy <= cloud130y + 80 + 32 && birdy >= cloud130y + 80 && cloud130x >= birdx && cloud130x + 32 <= birdx + 64)) && invisible130 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible130 = 1;
		}
		if (((birdx + 64 == cloud140x && ((birdy >= cloud140y && birdy <= cloud140y + 64) || (birdy + 64 <= cloud140y + 64 && birdy + 64 >= cloud140y))) || (birdy + 64 >= cloud140y && birdy + 64 <= cloud140y + 64 && (birdx >= cloud140x && birdx + 64 <= cloud140x + 64)))&& flag12==0){
			life--;
			flag12 = 1;
		}
		if (((birdx + 64 == cloud140x &&  cloud140y + 80 >= birdy &&  cloud140y + 80 + 32 <= birdy + 64) || (birdy <= cloud140y + 80 + 32 && birdy >= cloud140y + 80 && cloud140x >= birdx && cloud140x + 32 <= birdx + 64)) && invisible140 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible140 = 1;
		}
	
	}





	if (menuchange == 2){
		//Lifeloss//
		if (((birdx + 64 == cloud13x && ((birdy >= cloud13y && birdy <= cloud13y + 64) || (birdy + 64 <= cloud13y + 64 && birdy + 64 >= cloud13y))) || (birdy + 64 >= cloud13y && birdy + 64 <= cloud13y + 64 && (birdx >= cloud13x && birdx + 64 <= cloud13x + 64)))&& flag13==0){
			life--;
			flag13 = 1;
		}

		//scoreplus//
		if (((birdx + 64 == cloud13x &&  cloud13y + 80 >= birdy &&  cloud13y + 80 + 32 <= birdy + 64) || (birdy <= cloud13y + 80 + 32 && birdy >= cloud13y + 80 && cloud13x >= birdx && cloud13x + 32 <= birdx + 64)) && invisible13 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible13 = 1;
		}

		if (((birdx + 64 == cloud14x && ((birdy >= cloud14y && birdy <= cloud14y + 64) || (birdy + 64 <= cloud14y + 64 && birdy + 64 >= cloud14y))) || (birdy + 64 >= cloud14y && birdy + 64 <= cloud14y + 64 && (birdx >= cloud14x && birdx + 64 <= cloud14x + 64)))&& flag14==0){
			life--;
			flag14 = 1;
		}
		if (((birdx + 64 == cloud14x &&  cloud14y + 80 >= birdy &&  cloud14y + 80 + 32 <= birdy + 64) || (birdy <= cloud14y + 80 + 32 && birdy >= cloud14y + 80 && cloud14x >= birdx && cloud14x + 32 <= birdx + 64)) && invisible14 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible14 = 1;
		}

		if (((birdx + 64 == cloud15x && ((birdy >= cloud15y && birdy <= cloud15y + 64) || (birdy + 64 <= cloud15y + 64 && birdy + 64 >= cloud15y))) || (birdy + 64 >= cloud15y && birdy + 64 <= cloud15y + 64 && (birdx >= cloud15x && birdx + 64 <= cloud15x + 64)))&& flag15==0){
			life--;
			flag15 = 1;
		}
		if (((birdx + 64 == cloud15x &&  cloud15y + 80 >= birdy &&  cloud15y + 80 + 32 <= birdy + 64) || (birdy <= cloud15y + 80 + 32 && birdy >= cloud15y + 80 && cloud15x >= birdx && cloud15x + 32 <= birdx + 64)) && invisible15 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible15 = 1;
		}

		if (((birdx + 64 == cloud16x && ((birdy >= cloud16y && birdy <= cloud16y + 64) || (birdy + 64 <= cloud16y + 64 && birdy + 64 >= cloud16y))) || (birdy + 64 >= cloud16y && birdy + 64 <= cloud16y + 64 && (birdx >= cloud16x && birdx + 64 <= cloud16x + 64)))&& flag16==0){
			life--;
			flag16 = 1;
		}
		if (((birdx + 64 == cloud16x &&  cloud16y + 80 >= birdy &&  cloud16y + 80 + 32 <= birdy + 64) || (birdy <= cloud16y + 80 + 32 && birdy >= cloud16y + 80 && cloud16x >= birdx && cloud16x + 32 <= birdx + 64)) && invisible16 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible16 = 1;
		}

		if (((birdx + 64 == cloud17x && ((birdy >= cloud17y && birdy <= cloud17y + 64) || (birdy + 64 <= cloud17y + 64 && birdy + 64 >= cloud17y))) || (birdy + 64 >= cloud17y && birdy + 64 <= cloud17y + 64 && (birdx >= cloud17x && birdx + 64 <= cloud17x + 64)))&& flag17==0){
			life--;
			flag17 = 1;
		}
		if (((birdx + 64 == cloud17x &&  cloud17y + 80 >= birdy &&  cloud17y + 80 + 32 <= birdy + 64) || (birdy <= cloud17y + 80 + 32 && birdy >= cloud17y + 80 && cloud17x >= birdx && cloud17x + 32 <= birdx + 64)) && invisible17 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible17 = 1;
		}

		if (((birdx + 64 == cloud18x && ((birdy >= cloud18y && birdy <= cloud18y + 64) || (birdy + 64 <= cloud18y + 64 && birdy + 64 >= cloud18y))) || (birdy + 64 >= cloud18y && birdy + 64 <= cloud18y + 64 && (birdx >= cloud18x && birdx + 64 <= cloud18x + 64)))&& flag18==0){
			life--;
			flag18 = 1;
		}
		if (((birdx + 64 == cloud18x &&  cloud18y + 80 >= birdy &&  cloud18y + 80 + 32 <= birdy + 64) || (birdy <= cloud18y + 80 + 32 && birdy >= cloud18y + 80 && cloud18x >= birdx && cloud18x + 32 <= birdx + 64)) && invisible18 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible18 = 1;
		}

		if (((birdx + 64 == cloud19x && ((birdy >= cloud19y && birdy <= cloud19y + 64) || (birdy + 64 <= cloud19y + 64 && birdy + 64 >= cloud19y))) || (birdy + 64 >= cloud19y && birdy + 64 <= cloud19y + 64 && (birdx >= cloud19x && birdx + 64 <= cloud19x + 64)))&& flag19==0){
			life--;
			flag19 = 1;
		}
		if (((birdx + 64 == cloud19x &&  cloud19y + 80 >= birdy &&  cloud19y + 80 + 32 <= birdy + 64) || (birdy <= cloud19y + 80 + 32 && birdy >= cloud19y + 80 && cloud19x >= birdx && cloud19x + 32 <= birdx + 64)) && invisible19 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible19 = 1;
		}
	}

	if (menuchange == 3){
		//Lifeloss//
		if (((birdx + 64 == cloud20x && ((birdy >= cloud20y && birdy <= cloud20y + 64) || (birdy + 64 <= cloud20y + 64 && birdy + 64 >= cloud20y))) || (birdy + 64 >= cloud20y && birdy + 64 <= cloud20y + 64 && (birdx >= cloud20x && birdx + 64 <= cloud20x + 64)))&& flag20==0){
			life--;
			flag20 = 1;
		}

		//scoreplus//
		if (((birdx + 64 == cloud20x &&  cloud20y + 80 >= birdy &&  cloud20y + 80 + 32 <= birdy + 64) || (birdy <= cloud20y + 80 + 32 && birdy >= cloud20y + 80 && cloud20x >= birdx && cloud20x + 32 <= birdx + 64)) && invisible20 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible20 = 1;
		}

		if (((birdx + 64 == cloud21x && ((birdy >= cloud21y && birdy <= cloud21y + 64) || (birdy + 64 <= cloud21y + 64 && birdy + 64 >= cloud21y))) || (birdy + 64 >= cloud21y && birdy + 64 <= cloud21y + 64 && (birdx >= cloud21x && birdx + 64 <= cloud21x + 64)))&& flag21==0){
			life--;
			flag21 = 1;
		}
		if (((birdx + 64 == cloud21x &&  cloud21y + 80 >= birdy &&  cloud21y + 80 + 32 <= birdy + 64) || (birdy <= cloud21y + 80 + 32 && birdy >= cloud21y + 80 && cloud21x >= birdx && cloud21x + 32 <= birdx + 64)) && invisible21 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible21 = 1;
		}

		if (((birdx + 64 == cloud22x && ((birdy >= cloud22y && birdy <= cloud22y + 64) || (birdy + 64 <= cloud22y + 64 && birdy + 64 >= cloud22y))) || (birdy + 64 >= cloud22y && birdy + 64 <= cloud22y + 64 && (birdx >= cloud22x && birdx + 64 <= cloud22x + 64)))&& flag22==0){
			life--;
			flag22 = 1;
		}
		if (((birdx + 64 == cloud22x &&  cloud22y + 80 >= birdy &&  cloud22y + 80 + 32 <= birdy + 64) || (birdy <= cloud22y + 80 + 32 && birdy >= cloud22y + 80 && cloud22x >= birdx && cloud22x + 32 <= birdx + 64)) && invisible22 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible22 = 1;
		}

		if (((birdx + 64 == cloud23x && ((birdy >= cloud23y && birdy <= cloud23y + 64) || (birdy + 64 <= cloud23y + 64 && birdy + 64 >= cloud23y))) || (birdy + 64 >= cloud23y && birdy + 64 <= cloud23y + 64 && (birdx >= cloud23x && birdx + 64 <= cloud23x + 64)))&& flag23==0){
			life--;
			flag23 = 1;
		}
		if (((birdx + 64 == cloud23x &&  cloud23y + 80 >= birdy &&  cloud23y + 80 + 32 <= birdy + 64) || (birdy <= cloud23y + 80 + 32 && birdy >= cloud23y + 80 && cloud23x >= birdx && cloud23x + 32 <= birdx + 64)) && invisible23 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible23 = 1;
		}

		if (((birdx + 64 == cloud24x && ((birdy >= cloud24y && birdy <= cloud24y + 64) || (birdy + 64 <= cloud24y + 64 && birdy + 64 >= cloud24y))) || (birdy + 64 >= cloud24y && birdy + 64 <= cloud24y + 64 && (birdx >= cloud24x && birdx + 64 <= cloud24x + 64)))&& flag24==0){
			life--;
			flag24 = 1;
		}
		if (((birdx + 64 == cloud24x &&  cloud24y + 80 >= birdy &&  cloud24y + 80 + 32 <= birdy + 64) || (birdy <= cloud24y + 80 + 32 && birdy >= cloud24y + 80 && cloud24x >= birdx && cloud24x + 32 <= birdx + 64)) && invisible24 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible24 = 1;
		}

		if (((birdx + 64 == cloud25x && ((birdy >= cloud25y && birdy <= cloud25y + 64) || (birdy + 64 <= cloud25y + 64 && birdy + 64 >= cloud25y))) || (birdy + 64 >= cloud25y && birdy + 64 <= cloud25y + 64 && (birdx >= cloud25x && birdx + 64 <= cloud25x + 64)))&& flag25==0){
			life--;
			flag25 = 1;
		}
		if (((birdx + 64 == cloud25x &&  cloud25y + 80 >= birdy &&  cloud25y + 80 + 32 <= birdy + 64) || (birdy <= cloud25y + 80 + 32 && birdy >= cloud25y + 80 && cloud25x >= birdx && cloud25x + 32 <= birdx + 64)) && invisible25 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible25 = 1;
		}

		if ((birdx + 64 == cloud26x && ((birdy >= cloud26y && birdy <= cloud26y + 64) || (birdy + 64 <= cloud26y + 64 && birdy + 64 >= cloud26y))) || (birdy + 64 >= cloud26y && birdy + 64 <= cloud26y + 64 && (birdx >= cloud26x && birdx + 64 <= cloud26x + 64))){
			life--;
			flag26 = 1;
		}
		if (((birdx + 64 == cloud26x &&  cloud26y + 80 >= birdy &&  cloud26y + 80 + 32 <= birdy + 64) || (birdy <= cloud26y + 80 + 32 && birdy >= cloud26y + 80 && cloud26x >= birdx && cloud26x + 32 <= birdx + 64)) && invisible26 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible26 = 1;
		}

		if (((birdx + 64 == cloud27x && ((birdy >= cloud27y && birdy <= cloud27y + 64) || (birdy + 64 <= cloud27y + 64 && birdy + 64 >= cloud27y))) || (birdy + 64 >= cloud27y && birdy + 64 <= cloud27y + 64 && (birdx >= cloud27x && birdx + 64 <= cloud27x + 64)))&& flag27==0){
			life--;
			flag27 = 1;
		}
		if (((birdx + 64 == cloud27x &&  cloud27y + 80 >= birdy &&  cloud27y + 80 + 32 <= birdy + 64) || (birdy <= cloud27y + 80 + 32 && birdy >= cloud27y + 80 && cloud27x >= birdx && cloud27x + 32 <= birdx + 64)) && invisible27 == 0)
		{
			PlaySoundA("music\\coin", NULL, SND_ASYNC);
			score++;
			scorereal++;
			invisible27 = 1;
		}
	}

}
void enemymove(){
		
			enemyx = enemyx - 2;
}
void firemove(){

	if (firex > 0)
		firex -= 5;
	else{
		firex = bossx - 240;
		firey = bossy - 70;
	}
	if (birdx >= firex && birdx+64 <= firex + 256 && birdy >= firey && birdy+64 <= firey + 256 && menuchange == 4)
		life = 0;


}

void bossmove(){
	if (move == 0){

		bossy += 3;
		if (bossy >= 600 - 64)
			move = 1;

	}
	else
	{
		bossy -= 3;
		if (bossy <= 0)
			move = 0;

	}

	if (birdx + ballx + 32 >= bossx && birdx + ballx + 32 <= bossx + 64 && bally >= bossy && bally <= bossy + 64 && menuchange==4 && bossl==0){
	
		bosslife--;
		ballx = 0;
		ball = 0;
		ballmove = 0;
		bossl = 1;
	}

	if (bosslife == 0){
	
		menu = 7;
		score2 += 4;
		scorereal += 40;
	
	}

}

void iDraw()
{
	//place your drawing codes here	
	iClear();

	//Main_menu//
	if (menu == 0){
		if (cov >= 0 && cov < 30){
			iShowBMP(0, 0, "cov1.bmp");
			cov++;
		}
		if (cov >= 30 && cov < 60){
			iShowBMP(0, 0, "cov2.bmp");
			cov++;
		}
		if (cov >= 60 && cov < 90){
			iShowBMP(0, 0, "cov3.bmp");
			cov++;
		}
		if (cov >= 90 && cov < 120){
			iShowBMP(0, 0, "cov4.bmp");
			cov++;
		}
		if (cov >= 120){
			iShowBMP(0, 0, "cov5.bmp");

			if (z1 == 0){
				iShowBMP2(471, 200, "coin1.bmp", 0);
				z1++;
			}
			else if (z1 == 1){
				iShowBMP2(471, 200, "coin2.bmp", 0);
				z1++;
			}

			else if (z1 == 2)
			{
				iShowBMP2(471, 200, "coin3.bmp", 0);
				z1++;
			}
			else  if (z1 == 3){
				iShowBMP2(471, 200, "coin4.bmp", 0);
				z1 = 0;
			}

			if (z1 == 0){
				iShowBMP2(700, 200, "coin1.bmp", 0);
				z1++;
			}
			else if (z1 == 1){
				iShowBMP2(700, 200, "coin2.bmp", 0);
				z1++;
			}

			else if (z1 == 2)
			{
				iShowBMP2(700, 200, "coin3.bmp", 0);
				z1++;
			}
			else  if (z1 == 3){
				iShowBMP2(700, 200, "coin4.bmp", 0);
				z1 = 0;
			}


			if (z1 == 0){
				iShowBMP2(580, 200, "coin1.bmp", 0);
				z1++;
			}
			else if (z1 == 1){
				iShowBMP2(580, 200, "coin2.bmp", 0);
				z1++;
			}

			else if (z1 == 2)
			{
				iShowBMP2(580, 200, "coin3.bmp", 0);
				z1++;
			}
			else  if (z1 == 3){
				iShowBMP2(580, 200, "coin4.bmp", 0);
				z1 = 0;
			}


			if (z % 2 == 0)
				iShowBMP2(100, 480, "n11.bmp", 0);
			else
				iShowBMP2(100, 480, "n22.bmp", 0);
			z++;

			iShowBMP2(450, 400, "11570.bmp", 0);

			iShowBMP2(350, 470, "fire0.bmp", 0);
			iShowBMP2(180, 480, "fire0.bmp", 0);

		}
	}

	//Name Input//
	else if (menu == 1){
	
		iShowBMP(0, 0, "menu2.bmp");
		iShowBMP2(520, 80, "enter.bmp", 0);
		iSetColor(19, 234, 250);
		iRectangle(500, 200, 300, 40);
		if (mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(505, 215, name, GLUT_BITMAP_HELVETICA_18);
		}
	
	}

	//Game//
	else if (menu == 2){

		//common part//
		if (menuchange == 0){
			iShowBMP(0, 0, "maingame.bmp");
			iText(600, 570, "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (menuchange == 1){
			iShowBMP(0, 0, "sky4.bmp");
			iText(600, 570, "LEVEL 1", GLUT_BITMAP_TIMES_ROMAN_24);

		}
		if (menuchange == 2){
			iShowBMP(0, 0, "sky3.bmp");
			iText(600, 570, "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (menuchange == 3){
			iShowBMP(0, 0, "sky2.bmp");
			iText(600, 570, "LEVEL 2", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (menuchange==4)
			iShowBMP(0, 0, "vol.bmp");
		//back btn//
		iShowBMP(1300 - 150, 50, "back.bmp");


		//For birds constant movement//
		if (z % 2 == 0)
			iShowBMP2(birdx, birdy, "n11.bmp", 0);
		else
			iShowBMP2(birdx, birdy, "n22.bmp", 0);
		z++;
		//Life//
		iSetColor(19, 234, 250);
		iText(1300 - 50, 580, "LIFE");
		iSetColor(19, 234, 250);
		iText(50, 580, "SCORE");

		if (life == 3){
			iShowBMP2(945 + 300, 540, "heart.bmp", 0);
			iShowBMP2(945 + 300 - 32 - 3, 540, "heart.bmp", 0);
			iShowBMP2(945 + 300 - 64 - 6, 540, "heart.bmp", 0);


		}
		else if (life == 2){
			iShowBMP2(945 + 300, 540, "heart.bmp", 0);
			iShowBMP2(945 + 300 - 32 - 3, 540, "heart.bmp", 0);
		}
		else if (life == 1){

			iShowBMP2(945 + 300, 540, "heart.bmp", 0);

		}
		else if (life <= 0){

			menu = 3;
			gover = 0;

		}
		
			//Score//
			score1[1] = (score + 48);
			if (score1[1] > '9')
			{
				score1[1] = '0';
				score = 0;
				score2++;
			}
			score1[0] = score2 + 48;
			iText(70, 550, score1, GLUT_BITMAP_HELVETICA_18);

			//ballmove//

			



			if (ball == 1){
				if (menuchange!=4)
				iShowBMP2(birdx + ballx, bally, "Fireball22.bmp", 0);
				if (menuchange==4)
					iShowBMP2(birdx + ballx, bally, "balln.bmp", 0);

				ballx += 5;
				if (birdx + ballx >= 1000 + 300 - 32){
					ballx = 0;
					ball = 0;
					ballmove = 0;
				}
			}
			//finish common part//
		



			//level1

			if (menuchange == 0){
				//enemy//
				if (en == 0){
					iShowBMP2(enemyx, enemyy, "11570.bmp", 0);
				}
				//Cloud//
				iShowBMP2(cloud2x,cloud2y,"hi.bmp",0);

				//Cloud//
				iShowBMP2(cloudx, cloudy, "m3.bmp", 0);

				//coinmove//
				if (invisible != 1){
					if (z1 == 0){
						iShowBMP2(cloudx, cloudy + 80, "coin1.bmp", 0);
						z1++;
					}
					else if (z1 == 1){
						iShowBMP2(cloudx, cloudy + 80, "coin2.bmp", 0);
						z1++;
					}
					else if (z1 == 2)
					{
						iShowBMP2(cloudx, cloudy + 80, "coin3.bmp", 0);
						z1++;
					}
					else  if (z1 == 3){
						iShowBMP2(cloudx, cloudy + 80, "coin4.bmp", 0);
						z1 = 0;
					}
				}

				if (invisible2 != 1){
					if (z2 == 0){
						iShowBMP2(cloud2x, cloud2y + 80, "coin1.bmp", 0);
						z2++;
					}
					else if (z2 == 1){
						iShowBMP2(cloud2x, cloud2y + 80, "coin2.bmp", 0);
						z2++;
					}

					else if (z2 == 2)
					{
						iShowBMP2(cloud2x, cloud2y + 80, "coin3.bmp", 0);
						z2++;
					}
					else  if (z2 == 3){
						iShowBMP2(cloud2x, cloud2y + 80, "coin4.bmp", 0);
						z2 = 0;
					}
				}

				iShowBMP2(cloud3x, cloud3y, "meg1.bmp", 0);
				if (invisible3 != 1){
					if (z3 == 0){
						iShowBMP2(cloud3x, cloud3y + 80, "coin1.bmp", 0);
						z3++;
					}
					else if (z3 == 1){
						iShowBMP2(cloud3x, cloud3y + 80, "coin2.bmp", 0);
						z3++;
					}

					else if (z3 == 2)
					{
						iShowBMP2(cloud3x, cloud3y + 80, "coin3.bmp", 0);
						z3++;
					}
					else  if (z3 == 3){
						iShowBMP2(cloud3x, cloud3y + 80, "coin4.bmp", 0);
						z3 = 0;
					}
				}

				iShowBMP2(cloud4x, cloud4y, "hi.bmp", 0);
				if (invisible4 != 1){
					if (z4 == 0){
						iShowBMP2(cloud4x, cloud4y + 80, "coin1.bmp", 0);
						z4++;
					}
					else if (z4 == 1){
						iShowBMP2(cloud4x, cloud4y + 80, "coin2.bmp", 0);
						z4++;
					}

					else if (z4 == 2)
					{
						iShowBMP2(cloud4x, cloud4y + 80, "coin3.bmp", 0);
						z4++;
					}
					else  if (z4 == 3){
						iShowBMP2(cloud4x, cloud4y + 80, "coin4.bmp", 0);
						z4 = 0;
					}
				}
				iShowBMP2(cloud5x, cloud5y, "m2.bmp", 0);
				if (invisible5 != 1){
					if (z5 == 0){
						iShowBMP2(cloud5x, cloud5y + 80, "coin1.bmp", 0);
						z5++;
					}
					else if (z5 == 1){
						iShowBMP2(cloud5x, cloud5y + 80, "coin2.bmp", 0);
						z5++;
					}

					else if (z5 == 2)
					{
						iShowBMP2(cloud5x, cloud5y + 80, "coin3.bmp", 0);
						z5++;
					}
					else  if (z5 == 3){
						iShowBMP2(cloud5x, cloud5y + 80, "coin4.bmp", 0);
						z5 = 0;
					}
				}
				iShowBMP2(cloud6x, cloud6y, "meg1.bmp", 0);
				if (invisible6 != 1){
					if (z6 == 0){
						iShowBMP2(cloud6x, cloud6y + 80, "coin1.bmp", 0);
						z6++;
					}
					else if (z6 == 1){
						iShowBMP2(cloud6x, cloud6y + 80, "coin2.bmp", 0);
						z6++;
					}

					else if (z6 == 2)
					{
						iShowBMP2(cloud6x, cloud6y + 80, "coin3.bmp", 0);
						z6++;
					}
					else  if (z6 == 3){
						iShowBMP2(cloud6x, cloud6y + 80, "coin4.bmp", 0);
						z6 = 0;
					}
				}

				//if bird shoots the enemy//
				if (birdx + ballx + 32 >= enemyx && birdx + ballx + 32 <= enemyx + 128 && bally >= enemyy && bally <= enemyy + 128 && en == 0 && ball == 1){
					
					PlaySoundA("music\\boom", NULL, SND_ASYNC);
					ballx = 0;
					ball = 0;
					en = 1;
					score += 5;
					scorereal += 5;
					ballmove = 0;
				}


				if (en >= 1 && en < 20){
					iShowBMP2(enemyx, enemyy, "baamf.bmp", 0);
					en++;

				}
			}


			if (menuchange == 1){
				iShowBMP2(cloud8x, cloud8y, "meg1.bmp", 0);

				iShowBMP2(cloud9x, cloud9y, "hi.bmp", 0);

				iShowBMP2(cloud10x, cloud10y, "m2.bmp", 0);

				iShowBMP2(cloud11x, cloud11y, "m3.bmp", 0);

				iShowBMP2(cloud12x, cloud12y, "hi.bmp", 0);

				iShowBMP2(cloud130x, cloud130y, "meg1.bmp", 0);

				iShowBMP2(cloud140x, cloud140y, "m3.bmp", 0);

				//coinmove//
				if (invisible8 != 1){
					if (z8 == 0){
						iShowBMP2(cloud8x, cloud8y + 80, "coin1.bmp", 0);
						z8++;
					}
					else if (z8 == 1){
						iShowBMP2(cloud8x, cloud8y + 80, "coin2.bmp", 0);
						z8++;
					}
					else if (z8 == 2)
					{
						iShowBMP2(cloud8x, cloud8y + 80, "coin3.bmp", 0);
						z8++;
					}
					else  if (z8 == 3){
						iShowBMP2(cloud8x, cloud8y + 80, "coin4.bmp", 0);
						z8 = 0;
					}
				}

				if (invisible9 != 1){
					if (z9 == 0){
						iShowBMP2(cloud9x, cloud9y + 80, "coin1.bmp", 0);
						z9++;
					}
					else if (z9 == 1){
						iShowBMP2(cloud9x, cloud9y + 80, "coin2.bmp", 0);
						z9++;
					}

					else if (z9 == 2)
					{
						iShowBMP2(cloud9x, cloud9y + 80, "coin3.bmp", 0);
						z9++;
					}
					else  if (z9 == 3){
						iShowBMP2(cloud9x, cloud9y + 80, "coin4.bmp", 0);
						z9 = 0;
					}
				}
				if (invisible10 != 1){
					if (z10 == 0){
						iShowBMP2(cloud10x, cloud10y + 80, "coin1.bmp", 0);
						z10++;
					}
					else if (z10== 1){
						iShowBMP2(cloud10x, cloud10y + 80, "coin2.bmp", 0);
						z10++;
					}

					else if (z10 == 2)
					{
						iShowBMP2(cloud10x, cloud10y + 80, "coin3.bmp", 0);
						z10++;
					}
					else  if (z10 == 3){
						iShowBMP2(cloud10x, cloud10y + 80, "coin4.bmp", 0);
						z10 = 0;
					}
				}
				if (invisible11 != 1){
					if (z11 == 0){
						iShowBMP2(cloud11x, cloud11y + 80, "coin1.bmp", 0);
						z11++;
					}
					else if (z11 == 1){
						iShowBMP2(cloud11x, cloud11y + 80, "coin2.bmp", 0);
						z11++;
					}

					else if (z11 == 2)
					{
						iShowBMP2(cloud11x, cloud11y + 80, "coin3.bmp", 0);
						z11++;
					}
					else  if (z11 == 3){
						iShowBMP2(cloud11x, cloud11y + 80, "coin4.bmp", 0);
						z11 = 0;
					}
				}
				if (invisible12 != 1){
					if (z12 == 0){
						iShowBMP2(cloud12x, cloud12y + 80, "coin1.bmp", 0);
						z12++;
					}
					else if (z12 == 1){
						iShowBMP2(cloud12x, cloud12y + 80, "coin2.bmp", 0);
						z12++;
					}

					else if (z12 == 2)
					{
						iShowBMP2(cloud12x, cloud12y + 80, "coin3.bmp", 0);
						z12++;
					}
					else  if (z12 == 3){
						iShowBMP2(cloud12x, cloud12y + 80, "coin4.bmp", 0);
						z12 = 0;
					}
				}
				if (invisible130 != 1){
					if (z130 == 0){
						iShowBMP2(cloud130x, cloud130y + 80, "coin1.bmp", 0);
						z130++;
					}
					else if (z130 == 1){
						iShowBMP2(cloud130x, cloud130y + 80, "coin2.bmp", 0);
						z130++;
					}

					else if (z130 == 2)
					{
						iShowBMP2(cloud130x, cloud130y + 80, "coin3.bmp", 0);
						z130++;
					}
					else  if (z130 == 3){
						iShowBMP2(cloud130x, cloud130y + 80, "coin4.bmp", 0);
						z130 = 0;
					}
				}
				if (invisible140 != 1){
					if (z140 == 0){
						iShowBMP2(cloud140x, cloud140y + 80, "coin1.bmp", 0);
						z140++;
					}
					else if (z140 == 1){
						iShowBMP2(cloud140x, cloud140y + 80, "coin2.bmp", 0);
						z140++;
					}

					else if (z140 == 2)
					{
						iShowBMP2(cloud140x, cloud140y + 80, "coin3.bmp", 0);
						z140++;
					}
					else  if (z140 == 3){
						iShowBMP2(cloud140x, cloud140y + 80, "coin4.bmp", 0);
						z140 = 0;
					}
				}

			
			}



			if (menuchange == 2){
			
				iShowBMP2(cloud13x, cloud13y, "m2.bmp", 0);

				iShowBMP2(cloud14x, cloud14y, "m3.bmp", 0);

				iShowBMP2(cloud15x, cloud15y, "hi.bmp", 0);

				iShowBMP2(cloud16x, cloud16y, "meg1.bmp", 0);

				iShowBMP2(cloud17x, cloud17y, "m3.bmp", 0);

				iShowBMP2(cloud18x, cloud18y, "hi.bmp", 0);

				iShowBMP2(cloud19x, cloud19y, "meg1.bmp", 0);

			     
				if (invisible13 != 1){
					if (z13 == 0){
						iShowBMP2(cloud13x, cloud13y + 80, "coin1.bmp", 0);
						z13++;
					}
					else if (z13 == 1){
						iShowBMP2(cloud13x, cloud13y + 80, "coin2.bmp", 0);
						z13++;
					}
					else if (z13 == 2)
					{
						iShowBMP2(cloud13x, cloud13y + 80, "coin3.bmp", 0);
						z13++;
					}
					else  if (z13 == 3){
						iShowBMP2(cloud13x, cloud13y + 80, "coin4.bmp", 0);
						z13 = 0;
					}
				}

				if (invisible14 != 1){
					if (z14 == 0){
						iShowBMP2(cloud14x, cloud14y + 80, "coin1.bmp", 0);
						z14++;
					}
					else if (z14 == 1){
						iShowBMP2(cloud14x, cloud14y + 80, "coin2.bmp", 0);
						z14++;
					}

					else if (z14 == 2)
					{
						iShowBMP2(cloud14x, cloud14y + 80, "coin3.bmp", 0);
						z14++;
					}
					else  if (z14 == 3){
						iShowBMP2(cloud14x, cloud14y + 80, "coin4.bmp", 0);
						z14 = 0;
					}
				}
				if (invisible15 != 1){
					if (z15 == 0){
						iShowBMP2(cloud15x, cloud15y + 80, "coin1.bmp", 0);
						z15++;
					}
					else if (z15 == 1){
						iShowBMP2(cloud15x, cloud15y + 80, "coin2.bmp", 0);
						z15++;
					}

					else if (z15 == 2)
					{
						iShowBMP2(cloud15x, cloud15y + 80, "coin3.bmp", 0);
						z15++;
					}
					else  if (z15 == 3){
						iShowBMP2(cloud15x, cloud15y + 80, "coin4.bmp", 0);
						z15 = 0;
					}
				}

				if (invisible16 != 1){
					if (z16 == 0){
						iShowBMP2(cloud16x, cloud16y + 80, "coin1.bmp", 0);
						z16++;
					}
					else if (z16 == 1){
						iShowBMP2(cloud16x, cloud16y + 80, "coin2.bmp", 0);
						z16++;
					}

					else if (z16 == 2)
					{
						iShowBMP2(cloud16x, cloud16y + 80, "coin3.bmp", 0);
						z16++;
					}
					else  if (z16 == 3){
						iShowBMP2(cloud16x, cloud16y + 80, "coin4.bmp", 0);
						z16 = 0;
					}
				}

				if (invisible17 != 1){
					if (z17 == 0){
						iShowBMP2(cloud17x, cloud17y + 80, "coin1.bmp", 0);
						z17++;
					}
					else if (z17 == 1){
						iShowBMP2(cloud17x, cloud17y + 80, "coin2.bmp", 0);
						z17++;
					}

					else if (z17 == 2)
					{
						iShowBMP2(cloud17x, cloud17y + 80, "coin3.bmp", 0);
						z17++;
					}
					else  if (z17 == 3){
						iShowBMP2(cloud17x, cloud17y + 80, "coin4.bmp", 0);
						z17 = 0;
					}
				}

				if (invisible18 != 1){
					if (z18 == 0){
						iShowBMP2(cloud18x, cloud18y + 80, "coin1.bmp", 0);
						z18++;
					}
					else if (z18 == 1){
						iShowBMP2(cloud18x, cloud18y + 80, "coin2.bmp", 0);
						z18++;
					}

					else if (z18 == 2)
					{
						iShowBMP2(cloud18x, cloud18y + 80, "coin3.bmp", 0);
						z18++;
					}
					else  if (z18 == 3){
						iShowBMP2(cloud18x, cloud18y + 80, "coin4.bmp", 0);
						z18 = 0;
					}
				}

				if (invisible19 != 1){
					if (z19 == 0){
						iShowBMP2(cloud19x, cloud19y + 80, "coin1.bmp", 0);
						z19++;
					}
					else if (z19 == 1){
						iShowBMP2(cloud19x, cloud19y + 80, "coin2.bmp", 0);
						z19++;
					}

					else if (z19 == 2)
					{
						iShowBMP2(cloud19x, cloud19y + 80, "coin3.bmp", 0);
						z19++;
					}
					else  if (z19 == 3){
						iShowBMP2(cloud19x, cloud19y + 80, "coin4.bmp", 0);
						z19 = 0;
					}
				}
			}


			if (menuchange == 3){
				iShowBMP2(cloud20x, cloud20y, "hi.bmp", 0);

				iShowBMP2(cloud21x, cloud21y, "m2.bmp", 0);

				iShowBMP2(cloud22x, cloud22y, "m3.bmp", 0);

				iShowBMP2(cloud23x, cloud23y, "meg1.bmp", 0);

				iShowBMP2(cloud24x, cloud24y, "hi.bmp", 0);

				iShowBMP2(cloud25x, cloud25y, "m2.bmp", 0);

				iShowBMP2(cloud26x, cloud26y, "meg1.bmp", 0);

				iShowBMP2(cloud27x, cloud27y, "m3.bmp", 0);

				//coinmove//
				if (invisible20 != 1){
					if (z20 == 0){
						iShowBMP2(cloud20x, cloud20y + 80, "coin1.bmp", 0);
						z20++;
					}
					else if (z20 == 1){
						iShowBMP2(cloud20x, cloud20y + 80, "coin2.bmp", 0);
						z20++;
					}
					else if (z20 == 2)
					{
						iShowBMP2(cloud20x, cloud20y + 80, "coin3.bmp", 0);
						z20++;
					}
					else  if (z20 == 3){
						iShowBMP2(cloud20x, cloud20y + 80, "coin4.bmp", 0);
						z20 = 0;
					}
				}

				if (invisible21 != 1){
					if (z21 == 0){
						iShowBMP2(cloud21x, cloud21y + 80, "coin1.bmp", 0);
						z21++;
					}
					else if (z21 == 1){
						iShowBMP2(cloud21x, cloud21y + 80, "coin2.bmp", 0);
						z21++;
					}

					else if (z21 == 2)
					{
						iShowBMP2(cloud21x, cloud21y + 80, "coin3.bmp", 0);
						z21++;
					}
					else  if (z21 == 3){
						iShowBMP2(cloud21x, cloud21y + 80, "coin4.bmp", 0);
						z21 = 0;
					}
				}

				if (invisible22 != 1){
					if (z22 == 0){
						iShowBMP2(cloud22x, cloud22y + 80, "coin1.bmp", 0);
						z22++;
					}
					else if (z22 == 1){
						iShowBMP2(cloud22x, cloud22y + 80, "coin2.bmp", 0);
						z22++;
					}

					else if (z22 == 2)
					{
						iShowBMP2(cloud22x, cloud22y + 80, "coin3.bmp", 0);
						z22++;
					}
					else  if (z22 == 3){
						iShowBMP2(cloud22x, cloud22y + 80, "coin4.bmp", 0);
						z22 = 0;
					}
				}

				if (invisible23 != 1){
					if (z23 == 0){
						iShowBMP2(cloud23x, cloud23y + 80, "coin1.bmp", 0);
						z23++;
					}
					else if (z23 == 1){
						iShowBMP2(cloud23x, cloud23y + 80, "coin2.bmp", 0);
						z23++;
					}

					else if (z23 == 2)
					{
						iShowBMP2(cloud23x, cloud23y + 80, "coin3.bmp", 0);
						z23++;
					}
					else  if (z23 == 3){
						iShowBMP2(cloud23x, cloud23y + 80, "coin4.bmp", 0);
						z23 = 0;
					}
				}

				if (invisible24 != 1){
					if (z24 == 0){
						iShowBMP2(cloud24x, cloud24y + 80, "coin1.bmp", 0);
						z24++;
					}
					else if (z24 == 1){
						iShowBMP2(cloud24x, cloud24y + 80, "coin2.bmp", 0);
						z24++;
					}

					else if (z24 == 2)
					{
						iShowBMP2(cloud24x, cloud24y + 80, "coin3.bmp", 0);
						z24++;
					}
					else  if (z24 == 3){
						iShowBMP2(cloud24x, cloud24y + 80, "coin4.bmp", 0);
						z24 = 0;
					}
				}


				if (invisible25 != 1){
					if (z25 == 0){
						iShowBMP2(cloud25x, cloud25y + 80, "coin1.bmp", 0);
						z25++;
					}
					else if (z25 == 1){
						iShowBMP2(cloud25x, cloud25y + 80, "coin2.bmp", 0);
						z25++;
					}

					else if (z25 == 2)
					{
						iShowBMP2(cloud25x, cloud25y + 80, "coin3.bmp", 0);
						z25++;
					}
					else  if (z25 == 3){
						iShowBMP2(cloud25x, cloud25y + 80, "coin4.bmp", 0);
						z25 = 0;
					}
				}

				if (invisible26 != 1){
					if (z26 == 0){
						iShowBMP2(cloud26x, cloud26y + 80, "coin1.bmp", 0);
						z26++;
					}
					else if (z26 == 1){
						iShowBMP2(cloud26x, cloud26y + 80, "coin2.bmp", 0);
						z26++;
					}

					else if (z26 == 2)
					{
						iShowBMP2(cloud26x, cloud26y + 80, "coin3.bmp", 0);
						z26++;
					}
					else  if (z26 == 3){
						iShowBMP2(cloud26x, cloud26y + 80, "coin4.bmp", 0);
						z26 = 0;
					}
				}

				if (invisible27 != 1){
					if (z27 == 0){
						iShowBMP2(cloud27x, cloud27y + 80, "coin1.bmp", 0);
						z27++;
					}
					else if (z27 == 1){
						iShowBMP2(cloud27x, cloud27y + 80, "coin2.bmp", 0);
						z27++;
					}

					else if (z27 == 2)
					{
						iShowBMP2(cloud27x, cloud27y + 80, "coin3.bmp", 0);
						z27++;
					}
					else  if (z27 == 3){
						iShowBMP2(cloud27x, cloud27y + 80, "coin4.bmp", 0);
						z27 = 0;
					}
				}
			
			
			}

			if (menuchange == 4){
			
				
				iResumeTimer(t2);
				iResumeTimer(t3);
				if (bossz >= 1 && bossz<12)
					iShowBMP2(bossx, bossy, "char5.bmp", 0);
				if (bossz >= 12 && bossz < 24)
					iShowBMP2(bossx, bossy, "char6.bmp", 0);
				if (bossz >= 25)
					bossz = 0;
				bossz++;
				if (firex>0)
					iShowBMP2(firex, firey, "fireball11.bmp", 0);

				iSetColor(0, 255, 255);
				iText(600, 570, "BOSS LIFE", GLUT_BITMAP_HELVETICA_18);
				iRectangle(580, 530, 150, 30);
				if (bosslife == 6)
					iFilledRectangle(580, 530, 150, 30);
				if (bosslife == 5)
					iFilledRectangle(580, 530, 150 - 25, 30);
				if (bosslife == 4)
					iFilledRectangle(580, 530, 150 - 50, 30);
				if (bosslife == 3)
					iFilledRectangle(580, 530, 150 - 75, 30);
				if (bosslife == 2)
					iFilledRectangle(580, 530, 150 - 100, 30);
				if (bosslife == 1)
					iFilledRectangle(580, 530, 150 - 125, 30);
			
			
			}

	}

	//Game over//
	else if (menu == 3){
	
		if (gover>= 0 && gover < 30)
		{
			iShowBMP(0, 0, "gover1.bmp");
			gover++;

		}
		if (gover >= 30 && gover < 60)
		{
			iShowBMP(0, 0, "gover2.bmp");
			gover++;

		}
		if (gover >= 60 && gover < 90)
		{
			iShowBMP(0, 0, "gover3.bmp");
			gover++;

		}
		if (gover >= 90 && gover < 180)
		{
			iShowBMP(0, 0, "gover4.bmp");
			gover++;

		}

		if (gover >= 180)
			menu = 5;
	
	}


	//High Score//
	else if (menu == 4){
	
		iShowBMP(0, 0, "cartoon.bmp");
		iText(350, 500, "Name->", GLUT_BITMAP_HELVETICA_18);

		iText(750, 500, "Score->", GLUT_BITMAP_HELVETICA_18);
		iShowBMP(1300 - 150, 50, "back.bmp");
		f1 = n1;
		
		if (f1 >= 0 && strlen(info[f1].name)>1){
			iText(350, 450, info[f1].name, GLUT_BITMAP_TIMES_ROMAN_24);
			sco[1] = (info[f1].score % 10) + 48;
			sco[0] = (info[f1].score / 10) + 48;
			iText(750, 450, sco, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (f1 - 1 >= 0 && strlen(info[f1-1].name)>1){
			iText(350, 410, info[f1 - 1].name, GLUT_BITMAP_TIMES_ROMAN_24);
			sco[1] = (info[f1 - 1].score % 10) + 48;
			sco[0] = (info[f1 - 1].score / 10) + 48;
			iText(750, 410, sco, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (f1 - 2 >= 0 && strlen(info[f1-2].name)>1){
			iText(350, 370, info[f1 - 2].name, GLUT_BITMAP_TIMES_ROMAN_24);
			sco[1] = (info[f1 - 2].score % 10) + 48;
			sco[0] = (info[f1 - 2].score / 10) + 48;
			iText(750, 370, sco, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (f1 - 3 >= 0 && strlen(info[f1-3].name)>1){
			iText(350, 330, info[f1 - 3].name, GLUT_BITMAP_TIMES_ROMAN_24);
			sco[1] = (info[f1 - 3].score % 10) + 48;
			sco[0] = (info[f1 - 3].score / 10) + 48;
			iText(750, 330, sco, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (f1 - 4 >= 0 && strlen(info[f1-4].name)>1){
			iText(350, 290, info[f1 - 4].name, GLUT_BITMAP_TIMES_ROMAN_24);
			sco[1] = (info[f1 - 4].score % 10) + 48;
			sco[0] = (info[f1 - 4].score / 10) + 48;
			iText(750, 290, sco, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	
	
	}
	//tryagaain//
	else if (menu == 5){
	
		iShowBMP(0,0,"tryagain.bmp");
	
	}
	else if (menu == 7){
	
		if (delay >= 0 && delay < 40){
			iShowBMP(0, 0, "comgame.bmp");
			delay++;
		}
		if (delay == 40)
			menu = 1;
	}
	else if (menu == 8){

		if (story == 0)
			iShowBMP(0, 0, "story1.bmp");
		if (story == 1)
			iShowBMP(0, 0, "story2.bmp");
		if (story == 2)
			iShowBMP(0, 0, "story3.bmp");
		if (story == 3){
			menu = 2;
			iResumeTimer(t);
			iResumeTimer(t1);
		}
	}
	else if (menu == 6){
	
		iShowBMP(0, 0, "ins.bmp");
		iShowBMP(1300 - 150, 50, "back.bmp");

	}
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 945 && mx <= 1195 && my >= 600-189 && my <= 600-128 && menu == 0){

			z = 1, birdx = 64, birdy = 300, ball = 0, ballx = 32, z1 = 0, score = 0, score2 = 0;
			bosslife = 6,delay2=0;
			life = 3, enemyx = 1300 - 200, enemyy = 300, invisible = 0, en = 0, scorereal = 0, menuchange = 0, invisible2 = 0, invisible3 = 0, invisible4 = 0, invisible5 = 0, invisible6 = 0, invisible13 = 0, invisible14 = 0, invisible15 = 0, invisible16 = 0, invisible17 = 0, invisible18 = 0, invisible19 = 0, invisible8 = 0, invisible9 = 0, invisible10 = 0, invisible11 = 0, invisible12 = 0, invisible130 = 0, invisible140 = 0, invisible20 = 0, invisible21 = 0, invisible22 = 0, invisible23 = 0, invisible24 = 0, invisible25 = 0, invisible27 = 0, invisible26 = 0;
			//iResumeTimer(t);
			//iResumeTimer(t1);


			menu = 8;

		}
		if (mx >= 954 && mx <= 1203 && my >= 600-436 && my <= 600-362 && menu == 0){

			f1 = 0, n1 = 0, j = 0, s = 0;

			fp = fopen("Name.txt", "r");

			while (fscanf(fp, "%s %d", info[n1].name, &info[n1].score) != EOF)

				n1++;

			fclose(fp);

			for (j = 0; j < n1; j++)
			{
				for (s = 0; s < n1 - j; s++){
					if (info[s].score >info[s + 1].score){
						temp = info[s];
						info[s] = info[s + 1];
						info[s + 1] = temp;
					}
				}
			}


			menu = 4;

		}

		if (mx >= 67 && mx <= 177 && my >= 600-581 && my <= 600-482 && menu == 0)
			exit(0);
		if (mx >= 1026 && mx <= 1281 && my >= 600 - 314 && my <= 600 -245  && menu == 0)
			menu = 6;

		if (mx >= 500 && mx <= 500 + 300 && my >= 200 && my <= 200 + 40 && menu == 1)
			mode = 1;
		if (mx >= 1300 - 150 && mx <= 1300 - 150 + 100 && my >= 50 && my <= 50 + 50 && menu == 2){
			menu = 1;
			
		}
		if (mx >= 1152 && mx <=1233 && my >= 600-269 && my <=600-193  && menu == 5){
		
			menu = 1;
		
		}
		if (mx >= 997 && mx <= 1179 && my >= 600-271 && my <= 600-194 && menu == 5){
			z = 1, birdx = 64, birdy = 300,ball = 0, ballx = 32, z1 = 0, score = 0, score2 = 0;
			life = 3, enemyx = 1300 - 200, enemyy = 300, invisible = 0, en = 0, scorereal = 0, menuchange = 0, invisible2 = 0, invisible3 = 0, invisible4 = 0,invisible5=0,invisible6=0, invisible13 = 0, invisible14 = 0, invisible15 = 0, invisible16 = 0, invisible17 = 0, invisible18 = 0, invisible19 = 0, invisible8 = 0, invisible9 = 0, invisible10 = 0, invisible11 = 0, invisible12 = 0, invisible130 = 0, invisible140 = 0;
			invisible20 = 0, invisible21 = 0, invisible22 = 0, invisible23 = 0, invisible24 = 0, invisible25 = 0, invisible27 = 0, invisible26 = 0;
			bosslife = 6;
			iResumeTimer(t);

			iResumeTimer(t1);
			menu = 2;
		}

		if (mx >= 1300 - 150 && mx <= 1300 - 150 + 100 && my >= 50 && my <= 50 + 50 && menu == 4)
			menu = 0;

		if (mx >= 1300 - 150 && mx <= 1300 - 150 + 100 && my >= 50 && my <= 50 + 50 && menu == 6)
			menu = 0;


	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (menu == 2){
			ball = 1;
			bossl = 0;
			if (ballmove == 0){
				bally = birdy + 20;
				ballmove = 1;
			}
			PlaySoundA("music\\shoot", NULL, SND_ASYNC);
		}
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}


void iKeyboard(unsigned char key)
{
	
	if (key == 'w'){
		birdy += 5;

		if (birdy <= 0)
			life = 0;

	}
	if (key == 's'){
		birdy -= 5;

		if (birdy >= 600)
			life = 0;

	}
	if (key == '\r')
	{
		mode = 0;
		menu = 0;
		fp = fopen("Name.txt", "a");
		fprintf(fp, "%s", name);
		fprintf(fp, " %d", scorereal);
		fclose(fp);
		for (k = 0; k < len; k++)
			name[k] = NULL;
		    len = 0;

	}
	else if (mode == 1 && key!='\r')
	{
		name[len] = key;
		len++;

	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if (key == GLUT_KEY_UP)
		birdy+=5;
	if (key == GLUT_KEY_DOWN)
		birdy-=5;
	if (key == GLUT_KEY_LEFT){
		if (len >= 0){
			name[len] = NULL;
			len--;
		}
	}	
	if (key == GLUT_KEY_RIGHT && menu==8)
		story++;
}

int main()
{

	printf("%d",j);

		t=iSetTimer(20, birdmove);
		iPauseTimer(t);
		t1=iSetTimer(20, enemymove);
		iPauseTimer(t1);

  			t2=iSetTimer(30, bossmove);
			iPauseTimer(t2);
			t3=iSetTimer(30, firemove);
			iPauseTimer(t3);

	 
	iInitialize(1300, 600, "GAME");
	return 0;
}	