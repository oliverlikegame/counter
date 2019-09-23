#include<iostream>
#include<stdio.h>
#pragma comment(lib,"user32")
#pragma comment(lib,"gdi32")
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
extern "C" HWND WINAPI GetConsoleWindow();
void HideTheCursor() {
    CONSOLE_CURSOR_INFO cciCursor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
        cciCursor.bVisible = FALSE;
        SetConsoleCursorInfo(hStdOut, &cciCursor);
    }
}
void ShowTheCursor() {
    CONSOLE_CURSOR_INFO cciCursor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleCursorInfo(hStdOut, &cciCursor)) {
        cciCursor.bVisible = TRUE;
        SetConsoleCursorInfo(hStdOut, &cciCursor);
    }
}
int pic() {
    HWND  hwnd;
    HDC   hdc;
    HFONT hfont;
    HBITMAP hbm;
    HDC hdcBits;
    BITMAP bm;
 
    system("color F0");
    system("cls");
    HideTheCursor();
    hwnd  = GetConsoleWindow();
    hdc   = GetDC(hwnd);
	char matchMan[76][19]={ 
	"D:\\matchMAN\\1.bmp",
	"D:\\matchMAN\\2.bmp",
	"D:\\matchMAN\\3.bmp",
	"D:\\matchMAN\\4.bmp",
	"D:\\matchMAN\\5.bmp",
	"D:\\matchMAN\\6.bmp",
	"D:\\matchMAN\\7.bmp",
	"D:\\matchMAN\\8.bmp",
	"D:\\matchMAN\\9.bmp",
	"D:\\matchMAN\\10.bmp",
	"D:\\matchMAN\\11.bmp",
	"D:\\matchMAN\\12.bmp",
	"D:\\matchMAN\\13.bmp",
	"D:\\matchMAN\\14.bmp",
	"D:\\matchMAN\\15.bmp",
	"D:\\matchMAN\\16.bmp",
	"D:\\matchMAN\\17.bmp",
	"D:\\matchMAN\\18.bmp",
	"D:\\matchMAN\\19.bmp",
	"D:\\matchMAN\\20.bmp",
	"D:\\matchMAN\\21.bmp",
	"D:\\matchMAN\\22.bmp",
	"D:\\matchMAN\\23.bmp",
	"D:\\matchMAN\\24.bmp",
	"D:\\matchMAN\\25.bmp",
	"D:\\matchMAN\\26.bmp",
	"D:\\matchMAN\\27.bmp",
	"D:\\matchMAN\\28.bmp",
	"D:\\matchMAN\\29.bmp",
	"D:\\matchMAN\\30.bmp",
	"D:\\matchMAN\\31.bmp",
	"D:\\matchMAN\\32.bmp",
	"D:\\matchMAN\\33.bmp",
	"D:\\matchMAN\\34.bmp",
	"D:\\matchMAN\\35.bmp",
	"D:\\matchMAN\\36.bmp",
	"D:\\matchMAN\\37.bmp",
	"D:\\matchMAN\\38.bmp",
	"D:\\matchMAN\\39.bmp",
	"D:\\matchMAN\\40.bmp",
	"D:\\matchMAN\\41.bmp",
	"D:\\matchMAN\\42.bmp",
	"D:\\matchMAN\\43.bmp",
	"D:\\matchMAN\\44.bmp",
	"D:\\matchMAN\\45.bmp",
	"D:\\matchMAN\\46.bmp",
	"D:\\matchMAN\\47.bmp",
	"D:\\matchMAN\\48.bmp",
	"D:\\matchMAN\\49.bmp",
	"D:\\matchMAN\\50.bmp",
	"D:\\matchMAN\\51.bmp",
	"D:\\matchMAN\\52.bmp",
	"D:\\matchMAN\\53.bmp",
	"D:\\matchMAN\\54.bmp",
	"D:\\matchMAN\\55.bmp",
	"D:\\matchMAN\\56.bmp",
	"D:\\matchMAN\\57.bmp",
	"D:\\matchMAN\\58.bmp",
	"D:\\matchMAN\\59.bmp",
	"D:\\matchMAN\\60.bmp",
	"D:\\matchMAN\\61.bmp",
	"D:\\matchMAN\\62.bmp",
	"D:\\matchMAN\\63.bmp",
	"D:\\matchMAN\\64.bmp",
	"D:\\matchMAN\\65.bmp",
	"D:\\matchMAN\\66.bmp",
	"D:\\matchMAN\\67.bmp",
	"D:\\matchMAN\\68.bmp",
	"D:\\matchMAN\\69.bmp",
	"D:\\matchMAN\\70.bmp",
	"D:\\matchMAN\\71.bmp",
	"D:\\matchMAN\\72.bmp",
	"D:\\matchMAN\\73.bmp",
	"D:\\matchMAN\\74.bmp",
	"D:\\matchMAN\\75.bmp",
	"D:\\matchMAN\\76.bmp",
	};
	for(int i=0;i<76;i++){
    hbm=(HBITMAP)LoadImage(0,matchMan[i] ,IMAGE_BITMAP,0,0,LR_DEFAULTSIZE|LR_LOADFROMFILE);//路径报错麻烦属性——>配置属性——>常规——>项目默认值——>字符集，选为“使用多字节字符集
    if (hbm) {
        hdcBits = CreateCompatibleDC(hdc);
        GetObject (hbm, sizeof(BITMAP), &bm);
        SelectObject(hdcBits,hbm);
        Sleep(200);
		BitBlt(hdc,100,100,1980,1080,hdcBits,0,0,SRCCOPY); //
        DeleteDC(hdcBits);
        DeleteObject(hbm);
    }
	}
    hfont = CreateFont(24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "华文楷体");
    SelectObject(hdc,hfont);
    SetTextColor(hdc,RGB(255,255,255));
    SetBkMode(hdc,TRANSPARENT);
    TextOut(hdc,210,30,"matchMan",14);
	
    DeleteObject(hfont);
    ReleaseDC(hwnd,hdc);
    getch();
	system("color 07");
    system("cls");
    ShowTheCursor();
    return 0;
}






/*
extern	void man(){
	//裸装"
	char bareMan[32][140]={
	"                                    * * *                                                                                ",
	"                                  *       *                                                                              ",
	"                                  * M  M  *                                                                              ",
	"                                  *       *                                                                              ",
	"                                  *  0    *                                                                              ",
	"                                   *  *  *                                                                               ",
	"                        * * * *  *          *  * * *                                                                     ",
	"                      *                              *                                                                   ",
	"                     *                                *                                                                  ",
	"                    *     *                     *      *                                                                 ",
	"                   *     * *                    * *     *                                                                ",
	"                  *     *  *                    *  *     *                                                               ",
	"                 *     *   *                    *   *     *                                                              ",
	"                *     *    *                    *    *     *                                                             ",
	"               *     *     *                    *     *     *                                                            ",
	"              *     *      *                    *      *      *                                                          ",
	"             *     *       *                    *       *       *                                                        ",
	"            *     *        *                    *         *       *                                                      ",
	"               *           *          *         *            *  *                                                        ",
	"                           *         * *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        "
	};
	for(int row=0;row<32;row++){
		for(int col=0;col<140;col++){
			cout<<bareMan[row][col];
		}cout<<endl;
	}
	

	//头盔
	char hatMan[35][140]={
	"                                *           *                                                                            ",
	"                               **           **                                                                           ",
	"                              ***           ***                                                                          ",
	"                             *****  * * *  *****                                                                         ",
	"                             ****** ----- ******                                                                         ",
	"                              ***** ----- *****                                                                          ",
	"                                *** ----- ***                                                                            ",
	"                                  * ----- *                                                                              ",
	"                        * * * *  *          *  * * *                                                                     ",
	"                      *                              *                                                                   ",
	"                     *                                *                                                                  ",
	"                    *     *                     *      *                                                                 ",
	"                   *     * *                    * *     *                                                                ",
	"                  *     *  *                    *  *     *                                                               ",
	"                 *     *   *                    *   *     *                                                              ",
	"                *     *    *                    *    *     *                                                             ",
	"               *     *     *                    *     *     *                                                            ",
	"              *     *      *                    *      *      *                                                          ",
	"             *     *       *                    *       *       *                                                        ",
	"            *     *        *                    *         *       *                                                      ",
	"               *           *          *         *            *  *                                                        ",
	"                           *         * *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	};
	//盔甲
	char suitMan[35][140]={
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                    * * *                                                                                ",
	"                                  *       *                                                                              ",
	"                   *              * M  M  *               *                                                              ",
	"                  **              *       *               **                                                             ",
	"                 ***     * *      *  O    *    *    *    ***                                                             ",
	"                 **** * ***** *    *  *  *    * ******* ****                                                             ",
	"                  ***** * * * *  *       *  *  * * ** *****                                                              ",
	"                    *  *      *    *   *    *     *  ** ****                                                             ",
	"                  *****  *   *       *       *     *  * *****                                                            ",
	"                 ****   * * *  *    * *     *   * *   * * ****                                                           ",
	"                  *** *    *     * * U *  *     *  * *  * ***                                                            ",
	"                  *     *  *        * *         * *      *                                                               ",
	"                 *     *  *       *  *  *        *  *     *                                                              ",
	"                *     *          *       *           *     *                                                             ",
	"               *     *   *     *           *      *   *     *                                                            ",
	"              *     *        *               *         *     *                                                           ",
	"             *     *     * *                    * *     *      *                                                         ",
	"            *     *        *                    *        *       *                                                       ",
	"           *     *         *          *         *          *       *                                                     ",
	"             *             *         * *        *             *   *                                                      ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        "
	};
	//裤子
	char  pantsMan[35][140]={
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                    * * *                                                                                ",
	"                                  *       *                                                                              ",
	"                                  * M  M  *                                                                              ",
	"                                  *       *                                                                              ",
	"                                  *  0    *                                                                              ",
	"                                   *  *  *                                                                               ",
	"                        * * * *  *          *  * * *                                                                     ",
	"                      *                              *                                                                   ",
	"                     *                                *                                                                  ",
	"                    *     *                     *      *                                                                 ",
	"                   *     * *                    * *     *                                                                ",
	"                  *     *  *                    *  *     *                                                               ",
	"                 *     *   *                    *   *     *                                                              ",
	"                *     *    *                    *    *     *                                                             ",
	"               *     *     *                    *     *     *                                                            ",
	"              *     *      *      *      *      *      *      *                                                          ",
	"             *     *       *      *             *   *   *       *                                                        ",
	"            *     *        *       *      *               *       *                                                      ",
	"           *     *     *     *   |  *  *   |  *      *      *  *                                                         ",
	"              *                  |  *  *   |                                                                             ",
	"                      *     *    |---------|   *      *                                                                  ",
	"                           * *   |         |                                                                             ",
	"                     *   * * *   |---------|    * *    *                                                                 ",
	"                           *  *  |         |  * *                                                                        ",
	"                    *  *   *   *  --------- *   *   *  *                                                                 ",
	"                           *     *   *   *      *                                                                        ",
	"                      *    *       *    *       *   *                                                                    ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                                                                                                                         ",
	"                                                                                                                         "
	};
	//武器
	char armsMan[35][140]={
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                                                                                                         ",
	"                                    * * *                                                                                ",
	"                                  *       *                                                                              ",
	"                                  * M  M  *                                                                      O       ",
	"                                  *       *                                                                  O           ",
	"                                  *  0    *                                                              O    O          ",
	"                                   *  *  *                                                           O    O              ",
	"                        * * * *  *          *  * * *                                             O    O                  ",
	"                      *                              *                                       O    O                      ",
	"                     *                                *                                  O    O                          ",
	"                    *     *                     *      *                             O    O                              ",
	"                   *     * *                    * *     *                        O    O                                  ",
	"                  *     *  *                    *  *     *                   O    O                                      ",
	"                 *     *   *                    *   *     *              O    O                                          ",
	"                *     *    *                    *    *     *         O    O                                              ",
	"               *     *     *                    *     *     *    O    O                                                  ",
	"              *     *      *                    *      *      *   O                                                      ",
	"             *     *       *                    *       *       *                                                        ",
	"            *     *        *                    *    O    *       *                                                      ",
	"               *           *          *         *O    O      *  *                                                        ",
	"                           *         * *        * O                                                                      ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *O *        *                                                                        ",
	"                           *        * O*        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                         O *        *  *        *                                                                        ",
	"                     O    O*        *  *        *                                                                        ",
	"                 O    O    *        *  *        *                                                                        ",
	"             O    O        *        *  *        *                                                                        ",
	"              O            *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        ",
	"                           *        *  *        *                                                                        "
	};
	
//头盔上衣下衣武器
	char allMan[35][140]={
	"                                *           *                                                                            ",
	"                               **           **                                                                           ",
	"                              ***           ***                                                                          ",
	"                             *****  * * *  *****                                                                         ",
	"                             ****** ----- ******                                                                         ",         
	"                   *          ***** ----- *****           *                                                              ",
	"                  **            *** ----- ***             **                                                      0      ",
	"                 ***     * *      * ----- *    *    *    ***                                                  0          ", 
	"                 **** * ***** *  * *  *  * ** * ******* ****                                              0    0         ",
	"                  ***** * * * *  *       *  *  * * ** *****                                           O    0             ",
	"                    *  *      *    *   *    *     *  ** ****                                      O    O                 ",
	"                  *****  *   *       *       *     *  * *****                                 0    O                     ",
	"                 ****   * * *  *    * *     *   * *   * * ****                            0    O                         ",
	"                  *** *    *     * * U *  *     *  * *  * ***                         0    O                             ",
	"                  *     *  *        * *         * *      *                        0    O                                 ",
	"                 *     *  *       *  *  *        *  *     *                   0    O                                     ",
	"                *     *          *       *           *     *              0    O                                         ",
	"               *     *   *     *           *      *   *     *         O    O                                             ",
	"              *     *        *    *     *    *         *     *    O    O                                                 ",
	"             *     *     * *         *          * *     *      *   O                                                     ",
	"            *     *        *      *      *      *        *       *                                                       ",
	"              *          *      *             *   *    0   *       *                                                     ",
	"                           *       *      *             0    *  *                                                        ",
	"                       *     *   |  *  *   |  *      *                                                                   ",
	"                                 |  *  *   |                                                                             ",
	"                      *     *    |---------|   *      *                                                                  ",
	"                           * *   |         |                                                                             ",
	"                     *   * * *   |---------|    * *    *                                                                 ",
	"                           *  *  |         |  * *                                                                        ",
	"                    *  *   *   *  --------- *   *   *  *                                                                 ",
	"                           *     *   *   *      *                                                                        ",
	"                   O  *    *       *    *       *   *                                                                    ",
	"               O    O      *        *  *        *                                                                        ",
	"           O    O          *        *  *        *                                                                        ",
	"            O              *        *  *        *                                                                        "
	};


}
*/ 
