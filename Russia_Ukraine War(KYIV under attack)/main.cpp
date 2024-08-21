#include<cstdio>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<vector>
#include<math.h>
#define PI 3.1415
using namespace std;


const float DEG2RAD = 3.14159/180.0;

void midPointEllipse(float xradius, float yradius, float q)
{
	glBegin(GL_POLYGON);

	for(int i=0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD/q;
		glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
	}
	glEnd();
}

float _angle = 00.0f;

void updates(int value)
{
    _angle += 5.0;
    if (_angle > 360)
    {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(10, updates, 0);
}

float _angle1 = 00.0f;
float _angle2 = 00.0f;
GLfloat TSpeed = 0.0f;
GLfloat T2Speed = 0.0f;

void updatesT(int value)
{
    _angle1 -= TSpeed;
    if (_angle1 > 360)
    {
        _angle1 -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(10, updatesT, 0);
}

void updatesT2(int value)
{
    _angle2 -= T2Speed;
    if (_angle2 > 360)
    {
        _angle2 -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(10, updatesT2, 0);
}


//Update Car 1
GLfloat car1Position = 15.0f;
GLfloat car1Speed = 0.1f;
GLfloat car1Position1 = 15.0f;
GLfloat car1Speed1 = 0.11f;
GLfloat car1Scale = 1.0f;
GLfloat car1ScaleD = 0.002f;

void updateCar1(int value) {
    if(car1Position < -10.0f){
        car1Position = 15.0f;
        car1Position1 = 15.0f;
        car1Scale = 1.0;
    }

    car1Position -= car1Speed;
    car1Position1 -= car1Speed1;
    car1Scale -= car1ScaleD;

    glutPostRedisplay();
    glutTimerFunc(100, updateCar1, 0);
}

//Update Car 2
GLfloat car2Position = 30.0f;
GLfloat car2Speed = 0.1f;
GLfloat car2Position1 = 30.0f;
GLfloat car2Speed1 = 0.105f;
GLfloat car2Scale = 1.0f;
GLfloat car2ScaleD = 0.001f;

void updateCar2(int value) {
    if(car2Position < -12.0f){
        car2Position = 30.0f;
        car2Position1 = 30.0f;
        car2Scale = 1.0;
    }

    car2Position -= car2Speed;
    car2Position1 -= car2Speed1;
    car2Scale -= car2ScaleD;

    glutPostRedisplay();
    glutTimerFunc(100, updateCar2, 0);
}

//Update Car 3
GLfloat car3Position = 45.0f;
GLfloat car3Speed = 0.1f;
GLfloat car3Position1 = 45.0f;
GLfloat car3Speed1 = 0.105f;
GLfloat car3Scale = 1.0f;
GLfloat car3ScaleD = 0.0005f;

void updateCar3(int value) {
    if(car3Position < -20.0f){
        car3Position = 45.0f;
        car3Position1 = 45.0f;
        car3Scale = 1.0;
    }

    car3Position -= car3Speed;
    car3Position1 -= car3Speed1;
    car3Scale -= car3ScaleD;

    glutPostRedisplay();
    glutTimerFunc(100, updateCar3, 0);
}

//All Car stop

void allCarStop(float SetX, float SetY, float SetS){
    car1Speed = SetX;
    car1Speed1 = SetY;
    car1ScaleD = SetS;

    car2Speed = SetX;
    car2Speed1 = SetY;
    car2ScaleD = SetS;

    car3Speed = SetX;
    car3Speed1 = SetY;
    car3ScaleD = SetS;
}
//Make Fire
void makeFire(){
    glBegin(GL_POLYGON);
    glColor3f(0.99f, 0.76f, 0.00f);
    glVertex2f(47.6f,21.5f);
    glVertex2f(48.9f,16.3f);
    glVertex2f(50.6f,21.5f);
    glEnd();
 }

void makeFire1(){
    glBegin(GL_POLYGON);
    glColor3f(0.99f, 0.76f, 0.00f);
    glVertex2f(31.0f,44.5f);
    glVertex2f(32.5f,40.0f);
    glVertex2f(34.0f,44.5f);
    glEnd();
}

void makeFire2(){
    glBegin(GL_POLYGON);
    glColor3f(0.99f, 0.76f, 0.00f);
    glVertex2f(98.0f,67.2f);
    glVertex2f(99.3f,60.6f);
    glVertex2f(100.5f,67.2f);
    glEnd();
}

void makeFires(){
    makeFire();
    glPushMatrix();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire();
    glPopMatrix();
 }


void makeFires1(){
    makeFire1();
    glPushMatrix();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire1();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire1();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire1();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire1();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire1();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire1();
    glPopMatrix();
 }

void makeFires2(){
    makeFire2();
    glPushMatrix();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire2();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire2();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire2();
        glTranslatef(1.0f,1.0f,0.0f);
        makeFire2();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire2();
        glTranslatef(1.0f,-1.0f,0.0f);
        makeFire2();
    glPopMatrix();
}

//Fire
GLfloat fireX = 0.0f;
GLfloat fireY = 0.0f;

void Fire(){
    glPushMatrix();
        glScalef(fireX, fireY,0.0f);
        makeFires();
    glPopMatrix();
}

GLfloat fireX1 = 0.0f;
GLfloat fireY1 = 0.0f;

void Fire1(){
    glPushMatrix();
        glScalef(fireX1, fireY1,0.0f);
        makeFires1();
    glPopMatrix();
}

GLfloat fireX2 = 0.0f;
GLfloat fireY2 = 0.0f;

void Fire2(){
    glPushMatrix();
        glScalef(fireX2, fireY2,0.0f);
        makeFires2();
    glPopMatrix();
}

void FireA(float SetX, float SetY){
    fireX = SetX;
    fireY = SetY;
}

void FireA1(float SetX, float SetY){
    fireX1 = SetX;
    fireY1 = SetY;
}

void FireA2(float SetX, float SetY){
    fireX2 = SetX;
    fireY2 = SetY;
}

//Update Rocket

GLfloat rocketPosition = 0.0f;
GLfloat rocketSpeed = 0.0f;
GLfloat rocketPosition1 = 0.0f;
GLfloat rocketSpeed1 = 0.0f;

void updateRocket(int value) {
    if(rocketPosition < -45.0f ){
        rocketPosition = 0.0f;
        rocketPosition1 = 0.0f;
        rocketSpeed = 0.0f;
        rocketSpeed1 = 0.0f;
        FireA(1.0f,1.0f);
    }
    rocketPosition += rocketSpeed;
    rocketPosition1 += rocketSpeed1;
    glutPostRedisplay();
    glutTimerFunc(100, updateRocket, 5);
}

//Update Rocket2

GLfloat rocket2Position = 0.0f;
GLfloat rocket2Speed = 0.0f;
GLfloat rocket2Position1 = 0.0f;
GLfloat rocket2Speed1 = 0.0f;

void updateRocket2(int value) {
    if(rocket2Position > 65.0f ){
        rocket2Position = 0.0f;
        rocket2Position1 = 0.0f;
        rocket2Speed = 0.0f;
        rocket2Speed1 = 0.0f;
        FireA2(1.0f,1.0f);
    }
    rocket2Position += rocket2Speed;
    rocket2Position1 += rocket2Speed1;
    glutPostRedisplay();
    glutTimerFunc(100, updateRocket2, 5);
}

GLfloat HrocketPosition = 0.0f;
GLfloat HrocketSpeed = 0.0f;
GLfloat HrocketPosition1 = 0.0f;
GLfloat HrocketSpeed1 = 0.0f;

void updateHeliRocket(int value) {
    if(HrocketPosition < -65.0f ){
        HrocketPosition = 0.0f;
        HrocketPosition1 = 0.0f;
        HrocketSpeed = 0.0f;
        HrocketSpeed1 = 0.0f;
        FireA1(1.0f,1.0f);
    }
    HrocketPosition -= HrocketSpeed;
    HrocketPosition1 -= HrocketSpeed1;
    glutPostRedisplay();
    glutTimerFunc(100, updateHeliRocket, 5);
}

//Rocket luanch
void rocketStart(float Setx, float Sety){
    rocketSpeed=Setx;
    rocketSpeed1=Sety;
}

//Rocket luanch
void rocket2Start(float Setx, float Sety){
    rocket2Speed=Setx;
    rocket2Speed1=Sety;
}

//HeliRocket luanch
void HrocketStart(float Setx, float Sety){
    HrocketSpeed=Setx;
    HrocketSpeed1=Sety;
}

//Update Cloud
GLfloat cloud1Position = 0.0f;
GLfloat Cloud1speed = 0.07f;
GLfloat cloud2Position = 0.0f;
GLfloat Cloud2speed = 0.1f;
GLfloat cloud3Position = 0.0f;
GLfloat Cloud3speed = 0.12f;
GLfloat cloud4Position = 0.0f;
GLfloat Cloud4speed = 0.12f;
GLfloat cloud5Position = 0.0f;
GLfloat Cloud5speed = 0.08f;

void updateCloud1(int value){
    if(cloud1Position > 110.0f)
        cloud1Position = -25.0f;

    cloud1Position += Cloud1speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateCloud1, 0);
}

void updateCloud2(int value){
    if(cloud2Position > 95.0f)
        cloud2Position = -50.0f;

    cloud2Position += Cloud2speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateCloud2, 0);
}

void updateCloud3(int value){
    if(cloud3Position > 70.0f)
        cloud3Position = -70.0f;

    cloud3Position += Cloud3speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateCloud3, 0);
}

void updateCloud4(int value){
    if(cloud4Position > 50.0f)
        cloud4Position = -90.0f;

    cloud4Position += Cloud4speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateCloud4, 0);
}

void updateCloud5(int value){
    if(cloud5Position > 10.0f)
        cloud5Position = -130.0f;

    cloud5Position += Cloud5speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateCloud5, 0);
}

//Update Sun
GLfloat sunPosition = 0.0f;
GLfloat sunSpeed = 0.0f;

void updateSun(int value){
    if(sunPosition > 15.0f)
        sunPosition = -15.0f;

    sunPosition += sunSpeed;

    glutPostRedisplay();
    glutTimerFunc(200, updateSun, 0);
}

void sunset(float Setx){
    sunSpeed=Setx;
}

void sunset2(float Setx){
    sunSpeed=Setx;
}

//Update tank
GLfloat tankPosition = 40.0f;
GLfloat tankSpeed = 0.0f;

void updateTank(int value){

    tankPosition -= tankSpeed;

    glutPostRedisplay();
    glutTimerFunc(100, updateTank, 0);
}

//Update tank2
GLfloat tank2Position = -40.0f;
GLfloat tank2Speed = 0.0f;

void updateTank2(int value){

    tank2Position -= tank2Speed;

    glutPostRedisplay();
    glutTimerFunc(100, updateTank2, 0);
}

void tankStart(float Setx, float Sett){
    tankSpeed=Setx;
    TSpeed=Sett;
}

void tank2Start(float Setx, float Sett){
    tank2Speed=Setx;
    T2Speed=Sett;
}

void tankStop(float Setx, float Sett){
    tankSpeed=Setx;
    TSpeed=Sett;
}

void tank2Stop(float Setx, float Sett){
    tank2Speed=Setx;
    T2Speed=Sett;
}

//Update Heli
GLfloat heliPosition = 40.0f;
GLfloat heliSpeed = 0.0f;

void updateHeli(int value){

    heliPosition += heliSpeed;

    glutPostRedisplay();
    glutTimerFunc(100, updateHeli, 0);
}

void heliStart(float Setx){
    heliSpeed=Setx;
}

void heliStartInc(){
    heliSpeed=heliSpeed-0.1;
}

void heliStartDc(){
    heliSpeed=heliSpeed+0.1;
}



void heliStop(float Setx){
    heliSpeed=Setx;
}

void drawSFan(){
    glBegin(GL_QUADS);
    glColor3f(0.32f, 0.35f, 0.36f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.5f);
    glVertex2f(3.0f,3.0f);
    glVertex2f(0.5f,0.0f);
    glEnd();
}

void drawFans(){
    glRotatef(1,0.0,0.0,1.0);
    drawSFan();
    glRotatef(121,0.0,0.0,1.0);
    drawSFan();
    glRotatef(121,0.0,0.0,1.0);
    drawSFan();
}

void drawSFan1(){
    glBegin(GL_POLYGON);
    glColor3f(0.32f, 0.35f, 0.36f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.2f,0.0f);
    glVertex2f(1.0f,0.9f);
    glVertex2f(0.9f,1.0f);
    glVertex2f(0.0f,0.2f);
    glEnd();
}

void drawFans1(){
    glRotatef(1,0.0,0.0,1.0);
    drawSFan1();
    glRotatef(121,0.0,0.0,1.0);
    drawSFan1();
    glRotatef(121,0.0,0.0,1.0);
    drawSFan1();
}

//tank wheel
int tankW(float x,float y, float r){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.36f, 0.3f, 0.21f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

//tank2 wheel
int tank2W(float x,float y, float r){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.36f, 0.3f, 0.21f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

//tank wheel
void tankWheel(){
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.42f, 0.40f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.6f,0.6f);
    glEnd();
}

void tankWheels(){
    tankWheel();
    glRotatef(90,0.0,0.0,1.0);
    tankWheel();
    glRotatef(180,0.0,0.0,1.0);
    tankWheel();
    glRotatef(270,0.0,0.0,1.0);
    tankWheel();
}

//tank2 wheel
void tank2Wheel(){
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.55f, 0.42f, 0.40f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.6f,0.6f);
    glEnd();
}

void tank2Wheels(){
    tank2Wheel();
    glRotatef(90,0.0,0.0,1.0);
    tank2Wheel();
    glRotatef(180,0.0,0.0,1.0);
    tank2Wheel();
    glRotatef(270,0.0,0.0,1.0);
    tank2Wheel();
}

//Rocket
void rocket(){
    glPushMatrix();
        glTranslatef(rocketPosition,rocketPosition1, 0.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.35f, 0.27f, 0.32f);
        glVertex2f(100.4f, 64.3f);
        glVertex2f(100.5f, 65.7f);
        glVertex2f(101.7f, 64.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.27f, 0.32f);
        glVertex2f(98.6f, 62.6f);
        glVertex2f(98.7f, 63.1f);
        glVertex2f(100.9f, 65.2f);
        glVertex2f(101.3f, 64.8f);
        glVertex2f(99.1f, 62.7f);
        glEnd();
    glPopMatrix();

}

//Rocket2
void rocket2(){
    glPushMatrix();
        glTranslatef(rocket2Position,rocket2Position1, 0.0f);

        glTranslatef(155.0f,55.5f,0.0f);
        glRotated(-205,0.0f,0.0f,1.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.35f, 0.27f, 0.32f);
        glVertex2f(100.4f, 64.3f);
        glVertex2f(100.5f, 65.7f);
        glVertex2f(101.7f, 64.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.27f, 0.32f);
        glVertex2f(98.6f, 62.6f);
        glVertex2f(98.7f, 63.1f);
        glVertex2f(100.9f, 65.2f);
        glVertex2f(101.3f, 64.8f);
        glVertex2f(99.1f, 62.7f);
        glEnd();
    glPopMatrix();

}

void heliRocket(){
    glPushMatrix();
        //glScalef();
        glTranslatef(HrocketPosition,HrocketPosition1, 0.0f);
        glTranslatef(1.0f,99.5f,0.0f);
        glRotated(-60,0.0f,0.0f,1.0f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.35f, 0.27f, 0.32f);
        glVertex2f(100.4f, 64.3f);
        glVertex2f(100.5f, 65.7f);
        glVertex2f(101.7f, 64.5f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.27f, 0.32f);
        glVertex2f(98.6f, 62.6f);
        glVertex2f(98.7f, 63.1f);
        glVertex2f(100.9f, 65.2f);
        glVertex2f(101.3f, 64.8f);
        glVertex2f(99.1f, 62.7f);
        glEnd();
    glPopMatrix();

}

//tank
void tank(){

    rocket();

    glBegin(GL_QUADS);
    glColor3f(0.36f, 0.3f, 0.21f);
    glVertex2f(91.5f, 68.0f);
    glVertex2f( 94.5f, 70.3f);
    glVertex2f( 106.3f, 70.3f);
    glVertex2f(108.3f, 68.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.18f, 0.18f, 0.19f);
    glVertex2f(92.3f, 68.2f);
    glVertex2f( 94.7f, 70.1f);
    glVertex2f( 106.1f, 70.1f);
    glVertex2f(107.8f, 68.2f);
    glEnd();

    tankW(95.6,69.1,1.0);
    tankW(98.6,69.1,1.0);
    tankW(101.6,69.1,1.0);
    tankW(104.6,69.1,1.0);

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.3f, 0.21f);
    glVertex2f(90.1f, 68.3f);
    glVertex2f( 90.8f, 68.0f);
    glVertex2f( 108.9f, 68.0f);
    glVertex2f(109.6f, 68.3f);
    glVertex2f(109.6f, 67.7f);
    glVertex2f(108.9f, 67.1f);
    glVertex2f(90.8f, 67.1f);
    glVertex2f(90.1f, 67.7f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.3f, 0.21f);
    glVertex2f(90.6f, 65.3f);
    glVertex2f( 91.3f, 65.0f);
    glVertex2f( 107.9f, 65.0f);
    glVertex2f(108.6f, 65.3f);
    glVertex2f(108.6f, 64.7f);
    glVertex2f(107.9f, 64.1f);
    glVertex2f(91.3f, 64.1f);
    glVertex2f(90.6f, 64.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.65f, 0.49f);
    glVertex2f(91.6f, 65.3f);
    glVertex2f( 91.0f, 67.1f);
    glVertex2f( 108.6f, 67.1f);
    glVertex2f(108.2f, 65.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.73f, 0.65f, 0.49f);
    glVertex2f(92.6f, 64.8f);
    glVertex2f( 92.0f, 67.6f);
    glVertex2f( 107.7f, 67.6f);
    glVertex2f(107.2f, 64.8f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.38f, 0.34f);
    glVertex2f(92.9f, 67.6f);
    glVertex2f( 96.6f, 66.5f);

    glVertex2f( 105.0f, 66.5f);
    glVertex2f(106.7f, 67.6f);
    glVertex2f(106.4f, 64.8f);
    glVertex2f(104.6f, 63.9f);

    glVertex2f(96.6f, 63.9f);
    glVertex2f(93.4f, 64.8f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.42f, 0.4f);
    glVertex2f( 96.6f, 66.5f);
    glVertex2f( 105.0f, 66.5f);
    glVertex2f(104.6f, 63.9f);
    glVertex2f(96.6f, 63.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.42f, 0.4f);
    glVertex2f(92.9f, 67.6f);
    glVertex2f( 96.6f, 66.5f);
    glVertex2f( 105.0f, 66.5f);
    glVertex2f(106.7f, 67.6f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.35f, 0.38f, 0.34f);
    glVertex2f( 96.6f, 66.5f);
    glVertex2f( 105.0f, 66.5f);
    glEnd();

    glColor3f(0.35f, 0.38f, 0.34f);
    glPushMatrix();
        glTranslatef(100.8f,65.1f,0.0f);
        glScalef(0.05f,0.05f,1.0f);
        glRotated(0,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.35f, 0.38f, 0.34f);
    glPushMatrix();
        glTranslatef(100.8f,65.1f,0.0f);
        glScalef(0.05f,0.015f,1.0f);
        glRotated(0,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, 50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glLineWidth(20);
    glBegin(GL_LINES);
    glColor3f(0.35f, 0.38f, 0.34f);
    glVertex2f( 95.8f, 60.1f);
    glVertex2f( 99.5f, 63.6f);
    glEnd();

    glPushMatrix();
        glTranslatef(95.6f, 69.1f, 0.0f);
        glRotatef(_angle1, 0.0f, 0.0f,1.0f);
        tankWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(98.6f, 69.1f, 0.0f);
        glRotatef(_angle1, 0.0f, 0.0f,1.0f);
        tankWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(101.6f, 69.1f, 0.0f);
        glRotatef(_angle1, 0.0f, 0.0f,1.0f);
        tankWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(104.6f, 69.1f, 0.0f);
        glRotatef(_angle1, 0.0f, 0.0f,1.0f);
        tankWheels();
    glPopMatrix();

}

void tank2(){
    rocket2();
    glPushMatrix();
        glTranslatef(-35.0f,-6.0f,0.0f);
        glScalef(0.7f,0.7f,0.0f);

        glBegin(GL_QUADS);
        glColor3f(0.36f, 0.3f, 0.21f);
        glVertex2f(91.5f, 68.0f);
        glVertex2f( 94.5f, 70.3f);
        glVertex2f( 106.3f, 70.3f);
        glVertex2f(108.3f, 68.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.18f, 0.18f, 0.19f);
        glVertex2f(92.3f, 68.2f);
        glVertex2f( 94.7f, 70.1f);
        glVertex2f( 106.1f, 70.1f);
        glVertex2f(107.8f, 68.2f);
        glEnd();

        tank2W(95.6,69.1,1.0);
        tank2W(98.6,69.1,1.0);
        tank2W(101.6,69.1,1.0);
        tank2W(104.6,69.1,1.0);

        glBegin(GL_POLYGON);
        glColor3f(0.36f, 0.3f, 0.21f);
        glVertex2f(90.1f, 68.3f);
        glVertex2f( 90.8f, 68.0f);
        glVertex2f( 108.9f, 68.0f);
        glVertex2f(109.6f, 68.3f);
        glVertex2f(109.6f, 67.7f);
        glVertex2f(108.9f, 67.1f);
        glVertex2f(90.8f, 67.1f);
        glVertex2f(90.1f, 67.7f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.36f, 0.3f, 0.21f);
        glVertex2f(90.6f, 65.3f);
        glVertex2f( 91.3f, 65.0f);
        glVertex2f( 107.9f, 65.0f);
        glVertex2f(108.6f, 65.3f);
        glVertex2f(108.6f, 64.7f);
        glVertex2f(107.9f, 64.1f);
        glVertex2f(91.3f, 64.1f);
        glVertex2f(90.6f, 64.7f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.73f, 0.65f, 0.49f);
        glVertex2f(91.6f, 65.3f);
        glVertex2f( 91.0f, 67.1f);
        glVertex2f( 108.6f, 67.1f);
        glVertex2f(108.2f, 65.3f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.73f, 0.65f, 0.49f);
        glVertex2f(92.6f, 64.8f);
        glVertex2f( 92.0f, 67.6f);
        glVertex2f( 107.7f, 67.6f);
        glVertex2f(107.2f, 64.8f);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.35f, 0.38f, 0.34f);
        glVertex2f(92.9f, 67.6f);
        glVertex2f( 96.6f, 66.5f);

        glVertex2f( 105.0f, 66.5f);
        glVertex2f(106.7f, 67.6f);
        glVertex2f(106.4f, 64.8f);
        glVertex2f(104.6f, 63.9f);

        glVertex2f(96.6f, 63.9f);
        glVertex2f(93.4f, 64.8f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.55f, 0.42f, 0.4f);
        glVertex2f( 96.6f, 66.5f);
        glVertex2f( 105.0f, 66.5f);
        glVertex2f(104.6f, 63.9f);
        glVertex2f(96.6f, 63.9f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.55f, 0.42f, 0.4f);
        glVertex2f(92.9f, 67.6f);
        glVertex2f( 96.6f, 66.5f);
        glVertex2f( 105.0f, 66.5f);
        glVertex2f(106.7f, 67.6f);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.35f, 0.38f, 0.34f);
        glVertex2f( 96.6f, 66.5f);
        glVertex2f( 105.0f, 66.5f);
        glEnd();

        glColor3f(0.35f, 0.38f, 0.34f);
        glPushMatrix();
            glTranslatef(100.8f,65.1f,0.0f);
            glScalef(0.05f,0.05f,1.0f);
            glRotated(0,0.0f,0.0f,0.0f);
            midPointEllipse(50.0f, -50.0f, 2.0f);
        glPopMatrix();

        glEnd();

        glColor3f(0.35f, 0.38f, 0.34f);
        glPushMatrix();
            glTranslatef(100.8f,65.1f,0.0f);
            glScalef(0.05f,0.015f,1.0f);
            glRotated(0,0.0f,0.0f,0.0f);
            midPointEllipse(50.0f, 50.0f, 2.0f);
        glPopMatrix();

        glEnd();

        glLineWidth(20);
        glBegin(GL_LINES);
        glColor3f(0.38f, 0.38f, 0.34f);
        glVertex2f( 105.8f, 66.1f);
        glVertex2f( 100.0f, 63.5f);
        glEnd();

        glPushMatrix();
            glTranslatef(95.6f, 69.1f, 0.0f);
            glRotatef(_angle2, 0.0f, 0.0f,1.0f);
            tank2Wheels();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(98.6f, 69.1f, 0.0f);
            glRotatef(_angle2, 0.0f, 0.0f,1.0f);
            tank2Wheels();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(101.6f, 69.1f, 0.0f);
            glRotatef(_angle2, 0.0f, 0.0f,1.0f);
            tank2Wheels();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(104.6f, 69.1f, 0.0f);
            glRotatef(_angle2, 0.0f, 0.0f,1.0f);
            tank2Wheels();
        glPopMatrix();
    glPopMatrix();

}

//Heli Wheel
int heliWheel(){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;

    float x=97.6f;
    float y=42.7f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.36f, 0.28f, 0.32f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(1*cos(i*twicePi/triangleAmount)),
            y+(1*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

void heli(){

    heliRocket();
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.27f, 0.32f);
    glVertex2f(98.3f, 41.4f);
    glVertex2f(97.2f, 41.1f);
    glVertex2f(96.5f, 40.8f);
    glVertex2f(95.4f, 40.4f);
    glVertex2f(94.9f, 38.7f);
    glVertex2f(95.9f, 38.1f);
    glVertex2f(96.7f, 36.6f);
    glVertex2f(98.4f, 36.0f);
    glVertex2f(98.8f, 35.3f);
    glVertex2f(100.8f, 34.6f);
    glVertex2f(104.4f, 34.6f);
    glVertex2f(105.7f, 33.5f);
    glVertex2f(110.7f, 33.9f);
    glVertex2f(113.8f, 35.7f);
    glVertex2f(117.9f, 39.1f);
    glVertex2f(115.7f, 38.8f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.27f, 0.32f);
    glVertex2f(121.0f, 34.4f);
    glVertex2f(122.5f, 28.6f);
    glVertex2f(124.7f, 28.0f);
    glVertex2f(124.7f, 29.3f);
    glVertex2f(123.8f, 29.9f);
    glVertex2f(122.8f, 35.3f);
    glVertex2f(124.3f, 35.1f);
    glVertex2f(124.5f, 36.3f);
    glVertex2f(116.5f, 38.1f);
    glVertex2f(113.8f, 35.7f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.36f, 0.28f, 0.32f);
    glVertex2f(98.3f, 41.4f);
    glVertex2f(98.4f, 40.7f);
    glVertex2f(98.9f, 39.5f);
    glVertex2f(100.4f, 38.3f);
    glVertex2f(102.3f, 37.8f);
    glVertex2f(110.1f, 38.0f);
    glVertex2f(113.1f, 38.4f);
    glVertex2f(115.7f, 38.8f);
    glVertex2f(115.0f, 40.1f);
    glVertex2f(112.3f, 41.2f);
    glVertex2f(112.1f, 42.0f);
    glVertex2f(109.4f, 42.8f);
    glVertex2f(105.4f, 43.2f);
    glVertex2f(101.4f, 42.9f);
    glVertex2f(99.2f, 41.7f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(100.0f, 41.2f);
    glVertex2f(100.4f, 39.3f);
    glVertex2f(102.6f, 38.7f);
    glVertex2f(104.8f, 38.8f);
    glVertex2f(104.6f, 40.5f);
    glVertex2f(102.6f, 40.6f);
    glVertex2f(101.5f, 40.8f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(105.1f, 38.7f);
    glVertex2f(106.7f, 38.7f);
    glVertex2f(106.3f, 40.4f);
    glVertex2f(104.8f, 40.4f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(102.9f, 34.9f);
    glVertex2f(104.8f, 37.8f);
    glVertex2f(106.6f, 37.9f);
    glVertex2f(104.5f, 34.9f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(101.1f, 34.9f);
    glVertex2f(102.6f, 37.8f);
    glVertex2f(104.4f, 37.9f);
    glVertex2f(102.6f, 34.9f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(98.9f, 35.7f);
    glVertex2f(100.4f, 38.3f);
    glVertex2f(102.3f, 37.8f);
    glVertex2f(100.8f, 35.0f);

    glEnd();

    glPushMatrix();
        glTranslatef(123.8f, 29.1f, 0.0f);
        glRotatef(_angle, 0.0f, 0.0f,1.0f);
        drawFans();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(108.0f, 34.0f, 0.0f);
        glScalef(10.0f,1.0f,1.0f);
        glRotatef(_angle, 0.0f, 0.0f,1.0f);
        drawFans1();
    glPopMatrix();

    glLineWidth(50);
    glBegin(GL_LINES);
    glColor3f(0.36f, 0.28f, 0.32f);
    glVertex2f(106.3f,42.3f);
    glVertex2f(108.1f,44.8f);
    glEnd();

    glLineWidth(40);
    glBegin(GL_LINES);
    glColor3f(0.36f, 0.28f, 0.32f);
    glVertex2f(108.2f,44.5f);
    glVertex2f(105.5f,45.0f);
    glEnd();

    glEnd();

    //heliWheel();

    /*glLineWidth(50);
    glBegin(GL_LINES);
    glColor3f(0.36f, 0.28f, 0.32f);
    glVertex2f(99.0f,41.0f);
    glVertex2f(97.6f,42.7f);
    glEnd();*/

}


//Cloud Function
int cloud(float x,float y, float r, float r1){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r1*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

//Cloud
void cloud(){
    //cloud1
    glPushMatrix();
    glTranslatef(cloud1Position, 0.0f, 0.0f);
    cloud(23.0f,3.5f,2,1.5);
    cloud(21.5f,4.4f,1.5,1);
    cloud(21.5f,5.0f,2,0.8);
    cloud(23.7f,5.1f,2,1.0);
    cloud(25.5f,4.0f,1.5,1);
    cloud(25.5f,4.6f,2,0.8);
    glPopMatrix();

    //cloud2
    glPushMatrix();
    glTranslatef(cloud2Position, 0.0f, 0.0f);
    cloud(43.0f,2.5f,2,1.5);
    cloud(41.5f,3.4f,1.5,1);
    cloud(41.5f,4.0f,2,0.8);
    cloud(43.7f,4.1f,2,1.0);
    cloud(45.5f,3.0f,1.5,1);
    cloud(45.5f,3.6f,2,0.8);
    glPopMatrix();

    //cloud3
    glPushMatrix();
    glTranslatef(cloud3Position, 0.0f, 0.0f);
    cloud(63.0f,4.5f,2,1.5);
    cloud(61.5f,5.4f,1.5,1);
    cloud(61.5f,6.0f,2,0.8);
    cloud(63.7f,6.1f,2,1.0);
    cloud(65.5f,5.0f,1.5,1);
    cloud(65.5f,5.6f,2,0.8);
    glPopMatrix();

    //cloud4
    glPushMatrix();
    glTranslatef(cloud4Position, 0.0f, 0.0f);
    cloud(83.0f,3.5f,2,1.5);
    cloud(81.5f,4.4f,1.5,1);
    cloud(81.5f,5.0f,2,0.8);
    cloud(83.7f,5.1f,2,1.0);
    cloud(85.5f,4.0f,1.5,1);
    cloud(85.5f,4.6f,2,0.8);
    glPopMatrix();

    //cloud5
    glPushMatrix();
    glTranslatef(cloud5Position, 0.0f, 0.0f);
    cloud(123.0f,3.5f,2,1.5);
    cloud(121.5f,4.4f,1.5,1);
    cloud(121.5f,5.0f,2,0.8);
    cloud(123.7f,5.1f,2,1.0);
    cloud(125.5f,4.0f,1.5,1);
    cloud(125.5f,4.6f,2,0.8);
    glPopMatrix();
}

//Sun
int sun(){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;

    float x=18.0f;
    float y=5.0f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.96f,0.85f,0.3f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(4*cos(i*twicePi/triangleAmount)),
            y+(4*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

//footpath C
int ftCF(float x,float y, float r){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.52f, 0.47f, 0.51f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

int ftC(){
    ftCF(70.0f,73.2f,0.7);
    ftCF(72.0f,72.0f,0.7);

    ftCF(68.0f,71.2f,0.7);
    ftCF(70.0f,70.0f,0.7);

    ftCF(66.0f,69.2f,0.7);
    ftCF(68.0f,68.0f,0.7);

    ftCF(64.0f,67.2f,0.7);
    ftCF(66.0f,66.0f,0.7);

    ftCF(62.0f,65.2f,0.7);
    ftCF(64.0f,64.0f,0.7);

    ftCF(60.0f,63.2f,0.69);
    ftCF(62.0f,62.0f,0.69);

    ftCF(58.2f,61.1f,0.69);
    ftCF(59.8f,60.0f,0.69);
}

int ftCs(){
    glPushMatrix();
        glTranslatef(-0.4f, -0.4f,-1.0f);
        glScalef(0.8f,0.8f,1.0f);
        ftC();

        glTranslatef(0.0f,0.0f,1.0f);
        glScalef(0.8f,0.8f,0.0f);
        ftC();

        glTranslatef(0.0f,0.0f,1.0f);
        glScalef(0.8f,0.8f,0.0f);
        ftC();

        glTranslatef(0.0f,0.0f,1.0f);
        glScalef(0.8f,0.8f,0.0f);
        ftC();

        glTranslatef(0.0f,0.0f,0.0f);
        glScalef(0.8f,0.8f,0.0f);
        ftC();

    glPopMatrix();
}

void footPath(){
    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.29f, 0.31f);
    glVertex2f(67.5f, 73.0f);
    glVertex2f( 74.5f, 73.0f);
    glVertex2f( 21.7f, 20.8f);
    glVertex2f(18.0f, 20.8f);
    glEnd();
    ftC();
    ftCs();

}

void footPath2(){
    glPushMatrix();
        glTranslatef(-7.39f, -10.5f,1.0f);
        glScalef(1.0f,1.0f,1.0f);
        glRotated(14.5,0.0f,0.0f,1.0f);
        footPath();
    glPopMatrix();
}

//Road
void Road(){
    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(12.0f, 22.0f);
    glVertex2f( 43.0f, 73.0f);
    glVertex2f( 68.0f, 73.0f);
    glVertex2f(18.0f, 20.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.27f, 0.32f);
    glVertex2f(0.0f, 40.0f);
    glVertex2f( 0.0f, 44.0f);
    glVertex2f( 23.0f, 38.0f);
    glVertex2f(21.0f, 34.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(24.0f, 41.8f);
    glVertex2f( 35.6f, 38.6f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(23.0f, 40.8f);
    glVertex2f( 34.7f, 37.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(29.9f, 40.3f);
    glVertex2f( 41.4f, 55.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(30.3f, 40.1f);
    glVertex2f( 42.0f, 55.5f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(43.6f, 58.7f);
    glVertex2f( 54.8f, 73.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(44.1f, 58.5f);
    glVertex2f( 55.5f, 73.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(44.1f, 58.5f);
    glVertex2f( 55.5f, 73.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(31.5f, 41.6f);
    glVertex2f( 36.9f, 40.2f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(33.7f, 41.0f);
    glVertex2f( 38.7f, 47.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(39.4f, 47.7f);
    glVertex2f( 40.5f, 49.1f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(41.1f, 49.7f);
    glVertex2f( 42.4f, 51.3f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(43.0f, 52.0f);
    glVertex2f( 44.4f, 53.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(45.1f, 54.6f);
    glVertex2f( 46.6f, 56.3f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(47.4f, 57.3f);
    glVertex2f( 49.1f, 59.3f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(50.3f, 60.6f);
    glVertex2f( 51.9f, 62.6f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(53.2f, 64.1f);
    glVertex2f( 55.3f, 66.6f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(56.4f, 68.0f);
    glVertex2f( 58.8f, 70.8f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(18.5f, 32.8f);
    glVertex2f(27.8f, 30.5f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(18.0f, 31.8f);
    glVertex2f(27.1f, 29.5f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(22.5f, 30.8f);
    glVertex2f(14.7f, 20.8f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(23.0f, 30.6f);
    glVertex2f(15.0f, 20.8f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(18.0f, 34.8f);
    glVertex2f(20.2f, 38.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(17.0f, 34.8f);
    glVertex2f(19.2f, 39.0f);
    glEnd();
}

//Lamp 1
void Lamp(){
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.22f, 0.20f, 0.18f);
    glVertex2f(39.0f, 66.3f);
    glVertex2f( 39.0f, 54.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.22f, 0.20f, 0.18f);
    glVertex2f(38.9f, 54.5f);
    glVertex2f( 40.9f, 52.8f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.22f, 0.20f, 0.18f);
    glVertex2f(39.0f, 54.5f);
    glVertex2f( 41.7f, 53.8f);
    glEnd();
}

//Tree Leaf
int TreeLeaf(float x,float y, float r){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.20f, 0.40f, 0.22f);
    glClear(GL_COLOR_BUFFER_BIT);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r*sin(i*twicePi/triangleAmount))
        );
    }
    glEnd();
}

void Ground(){
    glBegin(GL_POLYGON);
    glColor3f(0.46f, 0.65f, 0.19f);
    glVertex2f(65.0f, 62.0f);
    glVertex2f(77.0f, 73.0f);
    glVertex2f(130.0f, 73.0f);
    glVertex2f(130.0f, 37.0f);
    glVertex2f(115.6f, 38.4f);

    glEnd();
}

void Tree(){
    //leaf
    TreeLeaf(34.5f,54.5f,4.0f);
    TreeLeaf(38.0f,53.0f,3.0f);
    TreeLeaf(36.5f,50.5f,2.0f);
    TreeLeaf(37.5f,56.5f,2.0f);
    TreeLeaf(32.5f,55.9f,3.0f);
    TreeLeaf(30.5f,53.5f,2.0f);
    TreeLeaf(32.8f,51.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(34.7f, 57.3f);
    glVertex2f( 34.7f, 65.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(34.7f, 57.5f);
    glVertex2f( 32.6f, 56.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(32.6f, 56.0f);
    glVertex2f(31.9f, 54.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(32.6f, 56.0f);
    glVertex2f(31.8f, 57.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(34.7f, 57.5f);
    glVertex2f( 38.0f, 56.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(36.0f, 57.0f);
    glVertex2f(36.2f, 54.2f);
    glEnd();
}

void Tree8(){
    //leaf
    TreeLeaf(26.5f,39.5f,4.0f);
    TreeLeaf(30.0f,38.0f,3.0f);
    TreeLeaf(28.5f,35.5f,2.0f);
    TreeLeaf(29.5f,41.5f,2.0f);
    TreeLeaf(24.5f,40.9f,3.0f);
    TreeLeaf(22.5f,38.5f,2.0f);
    TreeLeaf(24.8f,36.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(26.7f, 42.3f);
    glVertex2f( 26.7f, 50.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(26.7f, 42.5f);
    glVertex2f( 24.6f, 41.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(24.6f, 41.0f);
    glVertex2f(23.9f, 39.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(24.6f, 41.0f);
    glVertex2f(23.8f, 42.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(26.7f, 42.5f);
    glVertex2f( 30.0f, 41.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(28.0f, 42.0f);
    glVertex2f(28.2f, 39.2f);
    glEnd();
}

void Tree9(){
    //leaf
    TreeLeaf(14.0f,19.5f,3.0f);
    TreeLeaf(15.5f,18.1f,2.0f);
    TreeLeaf(15.3f,16.7f,1.5f);
    TreeLeaf(16.5f,20.5f,1.5f);
    TreeLeaf(11.0f,20.9f,1.5f);
    TreeLeaf(11.0f,19.5f,1.5f);
    TreeLeaf(12.8f,18.0f,2.0f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(14.2f, 21.3f);
    glVertex2f( 14.2f, 27.8f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(14.2f, 21.5f);
    glVertex2f( 12.1f, 20.0f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(12.1f, 20.0f);
    glVertex2f(11.4f, 19.2f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(12.2f, 20.0f);
    glVertex2f(11.3f, 21.2f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(14.2f, 21.5f);
    glVertex2f( 17.0f, 20.0f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(15.5f, 21.0f);
    glVertex2f(15.3f, 19.2f);
    glEnd();
}

void pTree(){
    glPushMatrix();
        glTranslatef(14.0f,7.0f,0.0f);
        glScalef(0.6f,0.6f,0.0f);
        Tree9();
        glTranslatef(6.5f,7.0f,0.0f);
        Tree9();
        glTranslatef(8.0f,7.0f,0.0f);
        Tree9();
        glTranslatef(7.0f,7.0f,0.0f);
        Tree9();
        glTranslatef(7.0f,7.0f,0.0f);
        Tree9();
        glTranslatef(7.0f,7.0f,0.0f);
        Tree9();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(23.0f,8.0f,0.0f);
        glScalef(0.5f,0.5f,0.0f);
        Tree9();
    glPopMatrix();
}

void pTree1(){
    glPushMatrix();
        glTranslatef(110.0f,28.0f,0.0f);
        glScalef(0.7f,0.7f,0.0f);
        Tree9();
        glTranslatef(-8.5f,6.0f,0.0f);
        Tree9();
        glTranslatef(-8.0f,5.0f,0.0f);
        Tree9();
        glTranslatef(-7.0f,4.0f,0.0f);
        Tree9();
        glTranslatef(-7.0f,3.0f,0.0f);
        Tree9();
        glTranslatef(-7.0f,2.0f,0.0f);
        Tree9();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(23.0f,8.0f,0.0f);
        glScalef(0.5f,0.5f,0.0f);
        Tree9();
    glPopMatrix();
}

void Tree1(){
    //leaf
    TreeLeaf(74.0f,58.5f,4.0f);
    TreeLeaf(78.0f,57.0f,3.0f);
    TreeLeaf(76.0f,54.5f,2.0f);
    TreeLeaf(77.0f,60.5f,2.0f);
    TreeLeaf(72.0f,59.9f,3.0f);
    TreeLeaf(70.0f,57.5f,2.0f);
    TreeLeaf(72.0f,55.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.0f, 61.7f);
    glVertex2f( 74.0f, 68.1f);
    glEnd();

    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.5f, 61.1f);
    glVertex2f( 74.5f, 68.1f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.2f, 61.8f);
    glVertex2f(70.8f, 59.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(70.8f, 59.9f);
    glVertex2f(69.8f, 56.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.2f, 61.8f);
    glVertex2f(72.8f, 59.4f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(72.8f, 59.4f);
    glVertex2f(72.7f, 56.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.2f, 61.8f);
    glVertex2f(76.7f, 58.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(77.0f, 55.5f);
    glVertex2f(76.7f, 58.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.8f, 56.2f);
    glVertex2f(76.7f, 58.6f);
    glEnd();
}

void Tree2(){
    //leaf
    TreeLeaf(84.0f,48.5f,4.0f);
    TreeLeaf(88.0f,47.0f,3.0f);
    TreeLeaf(86.0f,44.5f,2.0f);
    TreeLeaf(87.0f,50.5f,2.0f);
    TreeLeaf(82.0f,49.9f,3.0f);
    TreeLeaf(80.0f,47.5f,2.0f);
    TreeLeaf(82.0f,45.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.0f, 51.7f);
    glVertex2f( 84.0f, 58.1f);
    glEnd();

    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.5f, 51.1f);
    glVertex2f( 84.5f, 58.1f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.2f, 51.8f);
    glVertex2f(80.8f, 49.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(80.8f, 49.9f);
    glVertex2f(79.8f, 46.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.2f, 51.8f);
    glVertex2f(82.8f, 49.4f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(82.8f, 49.4f);
    glVertex2f(82.7f, 46.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.2f, 51.8f);
    glVertex2f(86.7f, 48.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(87.0f, 45.5f);
    glVertex2f(86.7f, 48.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(84.8f, 46.2f);
    glVertex2f(86.7f, 48.6f);
    glEnd();
}

void Tree3(){
    //leaf
    TreeLeaf(94.5f,44.5f,4.0f);
    TreeLeaf(98.0f,43.0f,3.0f);
    TreeLeaf(96.5f,40.5f,2.0f);
    TreeLeaf(97.5f,46.5f,2.0f);
    TreeLeaf(92.5f,45.9f,3.0f);
    TreeLeaf(90.5f,43.5f,2.0f);
    TreeLeaf(92.8f,41.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(94.7f, 47.3f);
    glVertex2f( 94.7f, 55.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(94.7f, 47.5f);
    glVertex2f( 92.6f, 46.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(92.6f, 46.0f);
    glVertex2f(91.9f, 44.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(92.6f, 46.0f);
    glVertex2f(91.8f, 47.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(94.7f, 47.5f);
    glVertex2f( 98.0f, 46.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(96.0f, 47.0f);
    glVertex2f(96.2f, 44.2f);
    glEnd();
}

void Tree4(){
    //leaf
    TreeLeaf(104.5f,39.5f,4.0f);
    TreeLeaf(108.0f,38.0f,3.0f);
    TreeLeaf(106.5f,35.5f,2.0f);
    TreeLeaf(107.5f,41.5f,2.0f);
    TreeLeaf(102.5f,40.9f,3.0f);
    TreeLeaf(100.5f,38.5f,2.0f);
    TreeLeaf(102.8f,36.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(104.7f, 42.3f);
    glVertex2f(104.7f, 50.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(104.7f, 42.5f);
    glVertex2f(102.6f, 41.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(102.6f, 41.0f);
    glVertex2f(101.9f, 39.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(102.6f, 41.0f);
    glVertex2f(101.8f, 42.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(104.7f, 42.5f);
    glVertex2f(108.0f, 41.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(106.0f, 42.0f);
    glVertex2f(106.2f, 39.2f);
    glEnd();
}

void Tree5(){
    //leaf
    TreeLeaf(114.0f,35.5f,4.0f);
    TreeLeaf(118.0f,34.0f,3.0f);
    TreeLeaf(116.0f,31.5f,2.0f);
    TreeLeaf(117.0f,37.5f,2.0f);
    TreeLeaf(112.0f,36.9f,3.0f);
    TreeLeaf(110.0f,34.5f,2.0f);
    TreeLeaf(112.0f,32.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.0f, 38.7f);
    glVertex2f(114.0f, 45.1f);
    glEnd();

    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.5f, 38.1f);
    glVertex2f(114.5f, 45.1f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.2f, 38.8f);
    glVertex2f(110.8f, 36.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(110.8f, 36.9f);
    glVertex2f(109.8f, 33.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.2f, 38.8f);
    glVertex2f(112.8f, 36.4f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(112.8f, 36.4f);
    glVertex2f(112.7f, 36.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.2f, 38.8f);
    glVertex2f(116.7f, 35.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(117.0f, 32.5f);
    glVertex2f(116.7f, 35.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(114.8f, 33.2f);
    glVertex2f(116.7f, 35.6f);
    glEnd();
}

void Tree6(){
    //leaf
    TreeLeaf(74.5f,47.5f,4.0f);
    TreeLeaf(78.0f,46.0f,3.0f);
    TreeLeaf(76.5f,45.5f,2.0f);
    TreeLeaf(77.5f,49.5f,2.0f);
    TreeLeaf(72.5f,48.9f,3.0f);
    TreeLeaf(70.5f,46.5f,2.0f);
    TreeLeaf(72.8f,44.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.7f, 50.3f);
    glVertex2f(74.7f, 58.3f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.7f, 50.5f);
    glVertex2f(72.6f, 49.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(72.6f, 49.0f);
    glVertex2f(71.9f, 47.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(72.6f, 49.0f);
    glVertex2f(71.8f, 50.2f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(74.7f, 50.5f);
    glVertex2f(78.0f, 49.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(76.0f, 50.0f);
    glVertex2f(76.2f, 47.2f);
    glEnd();
}

void Tree7(){
    //leaf
    TreeLeaf(124.0f,35.5f,4.0f);
    TreeLeaf(128.0f,34.0f,3.0f);
    TreeLeaf(126.0f,31.5f,2.0f);
    TreeLeaf(127.0f,37.5f,2.0f);
    TreeLeaf(122.0f,36.9f,3.0f);
    TreeLeaf(120.0f,34.5f,2.0f);
    TreeLeaf(122.0f,32.5f,2.5f);
    glEnd();

    //wood
    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.0f, 38.7f);
    glVertex2f(124.0f, 45.1f);
    glEnd();

    glLineWidth(100);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.5f, 38.1f);
    glVertex2f(124.5f, 45.1f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.2f, 38.8f);
    glVertex2f(120.8f, 36.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(120.8f, 36.9f);
    glVertex2f(119.8f, 33.7f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.2f, 38.8f);
    glVertex2f(122.8f, 36.4f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(122.8f, 36.4f);
    glVertex2f(122.7f, 36.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.2f, 38.8f);
    glVertex2f(126.7f, 35.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(127.0f, 32.5f);
    glVertex2f(126.7f, 35.6f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.15f, 0.0f);
    glVertex2f(124.8f, 33.2f);
    glVertex2f(126.7f, 35.6f);
    glEnd();
}

void Car1(){
    glPushMatrix();
        glTranslatef(-10.0f,0.0f,0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.19f, 0.60f, 0.76f);
        glVertex2f(45.65f,58.1f);
        glVertex2f(48.2f,61.5f);
        glVertex2f(49.2f,61.5f);
        glVertex2f(50.5f,60.8f);
        glVertex2f(50.85f,59.85f);
        glVertex2f(48.1f,56.4f);
        glVertex2f(47.2f,56.3f);
        glVertex2f(46.6f,56.5f);
        glVertex2f(46.3f,56.8f);
        glVertex2f(45.9f,57.1f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.11f, 0.13f, 0.16f);
        glVertex2f(46.4f,58.8f);
        glVertex2f(47.7f,58.8f);
        glVertex2f(48.35f,58.3f);
        glVertex2f(48.4f,57.3f);
        glVertex2f(47.7f,57.4f);
        glVertex2f(46.7f,58.1f);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.11f, 0.13f, 0.16f);
        glVertex2f(48.3f,59.8f);
        glVertex2f(48.0f,60.6f);
        glVertex2f(49.0f,60.6f);
        glVertex2f(49.7f,60.2f);
        glVertex2f(50.0f,59.4f);
        glVertex2f(49.1f,59.3f);
        glEnd();
    glPopMatrix();
}

void Car2(){
    glBegin(GL_POLYGON);
    glColor3f(0.19f, 0.60f, 0.76f);
    glVertex2f(45.65f,58.1f);
    glVertex2f(48.2f,61.5f);
    glVertex2f(49.2f,61.5f);
    glVertex2f(50.5f,60.8f);
    glVertex2f(50.85f,59.85f);
    glVertex2f(48.1f,56.4f);
    glVertex2f(47.2f,56.3f);
    glVertex2f(46.6f,56.5f);
    glVertex2f(46.3f,56.8f);
    glVertex2f(45.9f,57.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11f, 0.13f, 0.16f);
    glVertex2f(46.4f,58.8f);
    glVertex2f(47.7f,58.8f);
    glVertex2f(48.35f,58.3f);
    glVertex2f(48.4f,57.3f);
    glVertex2f(47.7f,57.4f);
    glVertex2f(46.7f,58.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11f, 0.13f, 0.16f);
    glVertex2f(48.3f,59.8f);
    glVertex2f(48.0f,60.6f);
    glVertex2f(49.0f,60.6f);
    glVertex2f(49.7f,60.2f);
    glVertex2f(50.0f,59.4f);
    glVertex2f(49.1f,59.3f);
    glEnd();


}

void Car3(){
    glBegin(GL_POLYGON);
    glColor3f(0.19f, 0.60f, 0.76f);
    glVertex2f(45.65f,58.1f);
    glVertex2f(48.2f,61.5f);
    glVertex2f(49.2f,61.5f);
    glVertex2f(50.5f,60.8f);
    glVertex2f(50.85f,59.85f);
    glVertex2f(48.1f,56.4f);
    glVertex2f(47.2f,56.3f);
    glVertex2f(46.6f,56.5f);
    glVertex2f(46.3f,56.8f);
    glVertex2f(45.9f,57.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11f, 0.13f, 0.16f);
    glVertex2f(46.4f,58.8f);
    glVertex2f(47.7f,58.8f);
    glVertex2f(48.35f,58.3f);
    glVertex2f(48.4f,57.3f);
    glVertex2f(47.7f,57.4f);
    glVertex2f(46.7f,58.1f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.11f, 0.13f, 0.16f);
    glVertex2f(48.3f,59.8f);
    glVertex2f(48.0f,60.6f);
    glVertex2f(49.0f,60.6f);
    glVertex2f(49.7f,60.2f);
    glVertex2f(50.0f,59.4f);
    glVertex2f(49.1f,59.3f);
    glEnd();
}

void Nbuilding(){
    glColor3f(0.0f, 0.40f, 0.45f);
    glPushMatrix();
        glTranslatef(4.6f,38.8f,0.0f);
        glScalef(0.1f,0.3f,1.0f);
        glRotated(0,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.0f, 0.64f, 0.72f);
    glPushMatrix();
        glTranslatef(4.6f,38.8f,0.0f);
        glScalef(0.08f,0.25f,1.0f);
        glRotated(0,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.79f, 0.74f, 0.0f);
	glVertex2f(4.6f,26.5f);
	glVertex2f(2.6f,32.5f);
	glVertex2f(6.6f,32.4f);
	glEnd();

	glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.79f, 0.74f, 0.0f);
    glVertex2f(2.4f,33.5f);
    glVertex2f(6.8f,33.3f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.79f, 0.74f, 0.0f);
    glVertex2f(2.2f,34.5f);
    glVertex2f(7.0f,34.3f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.79f, 0.74f, 0.0f);
    glVertex2f(2.0f,35.5f);
    glVertex2f(7.2f,35.3f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.79f, 0.74f, 0.0f);
    glVertex2f(1.8f,36.5f);
    glVertex2f(7.4f,36.3f);
    glEnd();

}

void building(){
    glBegin(GL_QUADS);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(48.2f,31.3f);
    glVertex2f(48.4f,43.1f);
    glVertex2f(77.5f,35.7f);
    glVertex2f(76.9f,25.7f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.71f, 0.76f, 0.82f);
    glVertex2f(48.8f,31.4f);
    glVertex2f(49.0f,42.95f);
    glVertex2f(76.9f,35.9f);
    glVertex2f(76.3f,25.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(48.2f,31.3f);
    glVertex2f(48.4f,43.1f);
    glVertex2f(31.9f,28.0f);
    glVertex2f(31.2f,19.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.71f, 0.76f, 0.82f);
    glVertex2f(48.0f,31.4f);
    glVertex2f(48.2f,43.0f);
    glVertex2f(31.9f,28.0f);
    glVertex2f(31.2f,19.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(70.7f,28.9f);
    glVertex2f(73.3f,28.4f);
    glVertex2f(73.3f,36.8f);
    glVertex2f(70.7f,37.4f);
    glEnd();

    glColor3f(0.47f, 0.45f, 0.49f);
    glPushMatrix();
        glTranslatef(63.2f,39.5f,0.0f);
        glScalef(0.05f,0.2f,1.0f);
        glRotated(-3.5,0.0f,0.0f,0.11f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.47f, 0.45f, 0.49f);
    glPushMatrix();
        glTranslatef(43.7f,39.0f,0.0f);
        glScalef(0.02f,0.15f,1.0f);
        glRotated(-6.5,0.0f,0.0f,-0.1f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.47f, 0.45f, 0.49f);
    glPushMatrix();
        glTranslatef(38.7f,34.4f,0.0f);
        glScalef(0.02f,0.14f,1.0f);
        glRotated(-6.5,0.0f,0.0f,-0.1f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.47f, 0.45f, 0.49f);
    glPushMatrix();
        glTranslatef(33.7f,29.8f,0.0f);
        glScalef(0.02f,0.13f,1.0f);
        glRotated(-6.5,0.0f,0.0f,-0.1f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(51.1f,32.9f);
    glVertex2f(54.5f,32.5f);
    glVertex2f(54.5f,41.4f);
    glVertex2f(51.1f,42.3f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.71f, 0.76f, 0.82f);
    glVertex2f(31.2f,19.8f);
    glVertex2f(48.2f,31.3f);
    glVertex2f(76.9f,25.7f);
    glVertex2f(51.3f,16.9f);
    glVertex2f(47.1f,16.8f);
    glVertex2f(41.8f,17.1f);
    glVertex2f(37.8f,17.6f);
    glVertex2f(33.5f,18.4f);
    glVertex2f(31.8f,18.9f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(31.2f,19.8f);
    glVertex2f(48.2f,31.3f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(48.2f,31.3f);
    glVertex2f(76.9f,25.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.47f, 0.45f, 0.49f);
    glVertex2f(48.2f,31.3f);
    glVertex2f(48.4f,43.1f);
    glEnd();

    glColor3f(0.47f, 0.46f, 0.49f);
    glPushMatrix();
        glTranslatef(52.0f,22.5f,0.0f);
        glScalef(0.17f,0.033f,1.0f);
        glRotated(-6,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, 50.0f, 2.0f);
    glPopMatrix();

	glEnd();

    glColor3f(0.47f, 0.46f, 0.49f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.17f,0.15f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.55f, 0.64f, 0.73f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.16f,0.14f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.47f, 0.46f, 0.49f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.15f,0.137f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.55f, 0.64f, 0.73f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.11f,0.13f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();



	glColor3f(0.47f, 0.46f, 0.49f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.10f,0.13f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.55f, 0.64f, 0.73f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.07f,0.118f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glColor3f(0.47f, 0.46f, 0.49f);
    glPushMatrix();
        glTranslatef(52.0f,23.0f,0.0f);
        glScalef(0.06f,0.117f,1.0f);
        glRotated(-12,0.0f,0.0f,0.0f);
        midPointEllipse(50.0f, -50.0f, 2.0f);
    glPopMatrix();

	glEnd();

	glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.98f, 0.87f, 0.66f);
    glVertex2f(51.9f,16.1f);
    glVertex2f(51.8f,11.0f);
    glEnd();


}

void building1(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.44f, 0.47f);
    glVertex2f(0.4f,38.0f);
    glVertex2f(16.2f,35.7f);
    glVertex2f(18.4f,43.3f);
    glVertex2f(0.4f,46.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(0.8f,38.2f);
    glVertex2f(15.8f,36.0f);
    glVertex2f(17.8f,42.9f);
    glVertex2f(0.8f,46.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.44f, 0.47f);
    glVertex2f(0.8f,46.3f);
    glVertex2f(0.8f,59.9f);
    glVertex2f(17.7f,56.6f);
    glVertex2f(17.7f,43.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(1.2f,46.3f);
    glVertex2f(1.2f,59.5f);
    glVertex2f(17.3f,56.2f);
    glVertex2f(17.3f,43.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.22f, 0.18f, 0.22f);
    glVertex2f(2.2f,47.3f);
    glVertex2f(2.2f,51.0f);
    glVertex2f(16.3f,47.8f);
    glVertex2f(16.3f,44.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.22f, 0.18f, 0.22f);
    glVertex2f(2.2f,52.0f);
    glVertex2f(2.2f,55.7f);
    glVertex2f(16.3f,52.4f);
    glVertex2f(16.3f,48.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(4.2f,46.3f);
    glVertex2f(4.2f,56.5f);
    glVertex2f(5.2f,56.2f);
    glVertex2f(5.2f,45.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(7.2f,46.3f);
    glVertex2f(7.2f,56.5f);
    glVertex2f(8.2f,56.2f);
    glVertex2f(8.2f,45.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(10.2f,44.3f);
    glVertex2f(10.2f,57.5f);
    glVertex2f(11.2f,56.2f);
    glVertex2f(11.2f,45.4f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.44f, 0.47f);
    glVertex2f(13.2f,44.0f);
    glVertex2f(13.2f,57.5f);
    glVertex2f(14.2f,56.2f);
    glVertex2f(14.2f,45.4f);
    glEnd();
}

void farBuilding(){
    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(0.0f,7.5f);
    glVertex2f(0.0f,20.8f);
    glVertex2f(4.5f,20.8f);
    glVertex2f(4.5f,5.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f,7.5f);
    glVertex2f(0.0f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f,20.8f);
    glVertex2f(4.5f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(4.5f,20.8f);
    glVertex2f(4.5f,5.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f,7.5f);
    glVertex2f(4.5f,5.9f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(8.3f,20.8f);
    glVertex2f(8.3f,8.1f);
    glVertex2f(8.8f,8.1f);
    glVertex2f(8.8f,7.2f);
    glVertex2f(9.2f,7.2f);
    glVertex2f(9.3f,6.0f);
    glVertex2f(10.2f,5.9f);
    glVertex2f(10.8f,4.0f);
    glVertex2f(11.5f,5.9f);
    glVertex2f(12.3f,6.0f);
    glVertex2f(12.4f,7.2f);
    glVertex2f(12.7f,7.2f);
    glVertex2f(12.7f,8.1f);
    glVertex2f(13.1f,8.1f);
    glVertex2f(13.1f,20.8f);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(8.3f,20.8f);
    glVertex2f(8.3f,8.1f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(9.3f,6.0f);
    glVertex2f(10.2f,5.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(8.3f,8.1f);
    glVertex2f(8.8f,8.1f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(8.8f,8.1f);
    glVertex2f(8.8f,7.2f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(8.8f,7.2f);
    glVertex2f(9.2f,7.2f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(9.2f,7.2f);
    glVertex2f(9.3f,6.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(9.2f,7.2f);
    glVertex2f(9.3f,6.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(10.2f,5.9f);
    glVertex2f(10.8f,4.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(10.8f,4.0f);
    glVertex2f(11.5f,5.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(11.5f,5.9f);
    glVertex2f(12.3f,6.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(12.3f,6.0f);
    glVertex2f(12.4f,7.2f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(12.4f,7.2f);
    glVertex2f(12.7f,7.2f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(12.7f,7.2f);
    glVertex2f(12.7f,8.1f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(12.7f,8.1f);
    glVertex2f(13.1f,8.1f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(13.1f,8.1f);
    glVertex2f(13.1f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(13.1f,20.8f);
    glVertex2f(8.3f,20.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(3.8f,9.0f);
    glVertex2f(4.4f,20.8f);
    glVertex2f(8.3f,20.8f);
    glVertex2f(9.3f,9.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(3.8f,9.0f);
    glVertex2f(4.4f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(4.4f,20.8f);
    glVertex2f(8.3f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(8.3f,20.8f);
    glVertex2f(9.3f,9.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(3.8f,9.0f);
    glVertex2f(9.3f,9.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(16.5f,20.8f);
    glVertex2f(16.5f,11.4f);
    glVertex2f(18.7f,9.0f);
    glVertex2f(20.7f,11.4f);
    glVertex2f(20.7f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(16.5f,20.8f);
    glVertex2f(16.5f,11.4f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(16.5f,11.4f);
    glVertex2f(18.7f,9.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(18.7f,9.0f);
    glVertex2f(20.7f,11.4f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(20.7f,11.4f);
    glVertex2f(20.7f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(16.5f,20.8f);
    glVertex2f(20.7f,20.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.65f, 0.65f, 0.65f);
    glVertex2f(13.1f,20.8f);
    glVertex2f(12.9f,14.6f);
    glVertex2f(17.1f,12.9f);
    glVertex2f(16.5f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(13.1f,20.8f);
    glVertex2f(12.9f,14.6f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(12.9f,14.6f);
    glVertex2f(17.1f,12.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(17.1f,12.9f);
    glVertex2f(16.5f,20.8f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(13.1f,20.8f);
    glVertex2f(16.5f,20.8f);
    glEnd();
}

void farBuilding1(){
    glPushMatrix();
    glTranslatef(20.7f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}

void farBuilding2(){
    glPushMatrix();
    glTranslatef(41.4f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}

void farBuilding3(){
    glPushMatrix();
    glTranslatef(62.1f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}

void farBuilding4(){
    glPushMatrix();
    glTranslatef(82.8f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}

void farBuilding5(){
    glPushMatrix();
    glTranslatef(103.6f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}

void farBuilding6(){
    glPushMatrix();
    glTranslatef(124.4f,0.0f,0.0f);
    farBuilding();
    glPopMatrix();
}


void grass(){
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.20f, 0.39f, 0.22f);
    glVertex2f(85.5f,67.0f);
    glVertex2f(84.0f,65.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.20f, 0.39f, 0.22f);
    glVertex2f(85.5f,67.0f);
    glVertex2f(84.7f,65.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.20f, 0.39f, 0.22f);
    glVertex2f(85.5f,67.0f);
    glVertex2f(87.0f,65.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.20f, 0.39f, 0.22f);
    glVertex2f(85.5f,67.0f);
    glVertex2f(86.3f,65.5f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.20f, 0.39f, 0.22f);
    glVertex2f(85.5f,67.0f);
    glVertex2f(85.5f,65.5f);
    glEnd();
}

void grassSS(){
    grass();
    glPushMatrix();
        glTranslatef(8.0f,0.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-8.0f,5.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.0f,5.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(13.0f,3.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20.0f,5.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20.0f,-5.0f,0.0f);
        //glScalef(f,f,f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.0f,2.0f,0.0f);
        glScalef(1.2f,1.0f,0.0f);
        grass();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.0f,-2.0f,0.0f);
        glScalef(1.2f,1.0f,0.0f);
        grass();
    glPopMatrix();
}

void grassS(){
    grassSS();
    glPushMatrix();
        glTranslatef(20.0f,5.0f,0.0f);
        //glScalef(f,f,f);
        grassSS();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20.0f,-5.0f,0.0f);
        //glScalef(f,f,f);
        grassSS();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(20.0f,-15.0f,0.0f);
        //glScalef(f,f,f);
        grassSS();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f,-15.0f,0.0f);
        //glScalef(f,f,f);
        grassSS();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-8.0f,-8.0f,0.0f);
        //glScalef(f,f,f);
        grassSS();
    glPopMatrix();

}


//sidebuilding1 window
int sd1W(float x,float y, float r){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.88f, 0.98f, 1.00f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

void sideBuilding(){
    glBegin(GL_QUADS);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(116.4f,8.6f);
    glVertex2f(116.4f,26.2f);
    glVertex2f(124.0f,26.2f);
    glVertex2f(124.0f,8.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(117.6f,10.1f);
    glVertex2f(117.6f,13.2f);
    glVertex2f(119.7f,13.2f);
    glVertex2f(119.7f,10.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(120.6f,10.1f);
    glVertex2f(120.6f,13.2f);
    glVertex2f(122.7f,13.2f);
    glVertex2f(122.7f,10.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(120.6f,15.1f);
    glVertex2f(120.6f,18.2f);
    glVertex2f(122.7f,18.2f);
    glVertex2f(122.7f,15.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(117.6f,15.1f);
    glVertex2f(117.6f,18.2f);
    glVertex2f(119.7f,18.2f);
    glVertex2f(119.7f,15.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(120.6f,20.1f);
    glVertex2f(120.6f,23.2f);
    glVertex2f(122.7f,23.2f);
    glVertex2f(122.7f,20.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(117.6f,20.1f);
    glVertex2f(117.6f,23.2f);
    glVertex2f(119.7f,23.2f);
    glVertex2f(119.7f,20.1f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(117.6f,11.7f);
    glVertex2f(119.7f,11.7f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.7f, 0.84f);
    glVertex2f(120.6f,11.7f);
    glVertex2f(122.7f,11.7f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(117.6f,16.7f);
    glVertex2f(119.7f,16.7f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(120.6f,16.7f);
    glVertex2f(122.7f,16.7f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(117.6f,21.7f);
    glVertex2f(119.7f,21.7f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(120.6f,21.7f);
    glVertex2f(122.7f,21.7f);
    glEnd();


    //2nd
    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(106.5f,6.5f);
    glVertex2f(106.5f,7.6f);
    glVertex2f(118.0f,7.6f);
    glVertex2f(118.0f,6.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.82f, 0.78f, 0.50f);
    glVertex2f(108.0f,7.6f);
    glVertex2f(108.0f,26.2f);
    glVertex2f(116.5f,26.2f);
    glVertex2f(116.5f,7.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(107.6f,18.0f);
    glVertex2f(107.6f,18.8f);
    glVertex2f(116.8f,18.8f);
    glVertex2f(116.8f,18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(107.6f,20.0f);
    glVertex2f(107.6f,20.8f);
    glVertex2f(116.8f,20.8f);
    glVertex2f(116.8f,20.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(108.8f,18.8f);
    glVertex2f(108.8f,20.0f);
    glVertex2f(109.5f,20.0f);
    glVertex2f(109.5f,18.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(110.8f,18.8f);
    glVertex2f(110.8f,20.0f);
    glVertex2f(111.5f,20.0f);
    glVertex2f(111.5f,18.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(112.8f,18.8f);
    glVertex2f(112.8f,20.0f);
    glVertex2f(113.5f,20.0f);
    glVertex2f(113.5f,18.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.66f, 0.62f, 0.40f);
    glVertex2f(114.8f,18.8f);
    glVertex2f(114.8f,20.0f);
    glVertex2f(115.5f,20.0f);
    glVertex2f(115.5f,18.8f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.46f, 0.41f, 0.34f);
    glVertex2f(109.1f,20.8f);
    glVertex2f(109.1f,26.3f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.46f, 0.41f, 0.34f);
    glVertex2f(111.1f,20.8f);
    glVertex2f(111.1f,26.3f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.46f, 0.41f, 0.34f);
    glVertex2f(113.1f,20.8f);
    glVertex2f(113.1f,26.3f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.46f, 0.41f, 0.34f);
    glVertex2f(115.1f,20.8f);
    glVertex2f(115.1f,26.3f);
    glEnd();

    glColor3f(0.88f, 0.98f, 1.0f);
    glPushMatrix();
        glTranslatef(110.5f,11.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(114.1f,11.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(110.5f,14.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(114.1f,14.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(110.5f,17.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(114.1f,17.5f,0.0f);
        glScalef(0.06f,0.12f,1.0f);
        glRotated(0.0,0.0f,0.0f,0.0f);
        midPointEllipse(20.0f, -20.0f, 2.0f);
    glPopMatrix();

	glEnd();

	//3rd

	glBegin(GL_QUADS);
    glColor3f(0.40f, 0.62f, 0.50f);
    glVertex2f(98.0f,8.5f);
    glVertex2f(98.0f,9.6f);
    glVertex2f(109.4f,9.6f);
    glVertex2f(109.4f,8.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.76f, 0.62f);
    glVertex2f(99.0f,9.6f);
    glVertex2f(99.0f,26.2f);
    glVertex2f(108.5f,26.2f);
    glVertex2f(108.5f,9.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(101.0f,12.0f);
    glVertex2f(101.0f,16.0f);
    glVertex2f(106.5f,16.0f);
    glVertex2f(106.5f,12.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40f, 0.62f, 0.50f);
    glVertex2f(100.0f,16.0f);
    glVertex2f(100.0f,17.0f);
    glVertex2f(107.5f,17.0f);
    glVertex2f(107.5f,16.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.76f, 0.62f);
    glVertex2f(101.0f,14.0f);
    glVertex2f(106.5f,14.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.76f, 0.62f);
    glVertex2f(103.75f,12.0f);
    glVertex2f(103.75f,16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.88f, 0.98f, 1.0f);
    glVertex2f(101.0f,19.0f);
    glVertex2f(101.0f,23.0f);
    glVertex2f(106.5f,23.0f);
    glVertex2f(106.5f,19.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.40f, 0.62f, 0.50f);
    glVertex2f(100.0f,23.0f);
    glVertex2f(100.0f,24.0f);
    glVertex2f(107.5f,24.0f);
    glVertex2f(107.5f,23.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.76f, 0.62f);
    glVertex2f(101.0f,21.0f);
    glVertex2f(106.5f,21.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.50f, 0.76f, 0.62f);
    glVertex2f(103.75f,19.0f);
    glVertex2f(103.75f,23.0f);
    glEnd();

}

void sideBuilding1(){
    //1st
    glBegin(GL_QUADS);
    glColor3f(1.00f, 0.91f, 0.21f);
    glVertex2f(72.2f,12.9f);
    glVertex2f(72.2f,26.5f);
    glVertex2f(78.8f,26.5f);
    glVertex2f(78.8f,12.9f);
    glEnd();

    sd1W(74.0f,15.0f, 1.0);
    sd1W(77.0f,15.0f, 1.0);

    sd1W(74.0f,18.0f, 1.0);
    sd1W(77.0f,18.0f, 1.0);

    sd1W(74.0f,21.0f, 1.0);
    sd1W(77.0f,21.0f, 1.0);

    sd1W(74.0f,24.0f, 1.0);
    sd1W(77.0f,24.0f, 1.0);

    //2nd
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.48f, 0.65f);
    glVertex2f(61.2f,8.9f);
    glVertex2f(61.2f,26.5f);
    glVertex2f(72.2f,26.5f);
    glVertex2f(72.2f,8.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 0.91f, 0.21f);
    glVertex2f(67.0f,7.9f);
    glVertex2f(67.0f,20.5f);
    glVertex2f(71.5f,20.5f);
    glVertex2f(71.5f,7.9f);
    glEnd();

    sd1W(68.2f,10.0f, 0.8);
    sd1W(70.3f,10.0f, 0.8);

    sd1W(68.2f,13.0f, 0.8);
    sd1W(70.3f,13.0f, 0.8);

    sd1W(68.2f,16.0f, 0.8);
    sd1W(70.3f,16.0f, 0.8);

    sd1W(68.2f,19.0f, 0.8);
    sd1W(70.3f,19.0f, 0.8);

    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.59f, 0.80f);
    glVertex2f(60.5f,10.0f);
    glVertex2f(60.5f,18.0f);
    glVertex2f(66.5f,18.0f);
    glVertex2f(66.5f,10.0f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(61.0f,11.0f);
    glVertex2f(66.0f,11.0f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(61.0f,13.0f);
    glVertex2f(66.0f,13.0f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(61.0f,15.0f);
    glVertex2f(66.0f,15.0f);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(61.0f,17.0f);
    glVertex2f(66.0f,17.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.59f, 0.80f);
    glVertex2f(61.2f,18.5f);
    glVertex2f(61.2f,20.5f);
    glVertex2f(66.5f,20.5f);
    glVertex2f(66.5f,18.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(61.5f,18.5f);
    glVertex2f(61.5f,20.5f);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(62.0f,18.5f);
    glVertex2f(62.0f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(62.5f,18.5f);
    glVertex2f(62.5f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(63.0f,18.5f);
    glVertex2f(63.0f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(63.5f,18.5f);
    glVertex2f(63.5f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(64.0f,18.5f);
    glVertex2f(64.0f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(64.5f,18.5f);
    glVertex2f(64.5f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.0f,18.5f);
    glVertex2f(65.0f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(65.5f,18.5f);
    glVertex2f(65.5f,20.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(66.0f,18.5f);
    glVertex2f(66.0f,20.5f);
    glEnd();

    sd1W(63.2f,23.5f, 1.5);
    sd1W(66.7f,23.5f, 1.5);
    sd1W(70.2f,23.5f, 1.5);

}

void sideBuilding2(){
    //1st
    ////1.1
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.25f, 0.91f);
    glVertex2f(86.0f,19.1f);
    glVertex2f(86.0f,22.8f);
    glVertex2f(96.4f,22.8f);
    glVertex2f(96.4f,19.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(87.4f,19.8f);
    glVertex2f(87.4f,22.2f);
    glVertex2f(88.9f,22.2f);
    glVertex2f(88.9f,19.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(89.4f,19.8f);
    glVertex2f(89.4f,22.2f);
    glVertex2f(90.9f,22.2f);
    glVertex2f(90.9f,19.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(86.9f,22.8f);
    glVertex2f(86.9f,23.9f);
    glVertex2f(92.0f,23.9f);
    glVertex2f(92.0f,22.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(93.4f,22.8f);
    glVertex2f(93.4f,23.9f);
    glVertex2f(94.4f,23.9f);
    glVertex2f(94.4f,22.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(95.4f,22.8f);
    glVertex2f(95.4f,23.9f);
    glVertex2f(96.4f,23.9f);
    glVertex2f(96.4f,22.8f);
    glEnd();

    ////1.2

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.25f, 0.91f);
    glVertex2f(86.0f,23.8f);
    glVertex2f(86.0f,27.6f);
    glVertex2f(96.4f,27.6f);
    glVertex2f(96.4f,23.8f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(87.4f,24.6f);
    glVertex2f(87.4f,27.0f);
    glVertex2f(88.9f,27.0f);
    glVertex2f(88.9f,24.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(89.4f,24.6f);
    glVertex2f(89.4f,27.0f);
    glVertex2f(90.9f,27.0f);
    glVertex2f(90.9f,24.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(86.9f,27.6f);
    glVertex2f(86.9f,28.7f);
    glVertex2f(92.0f,28.7f);
    glVertex2f(92.0f,27.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(93.4f,27.6f);
    glVertex2f(93.4f,28.7f);
    glVertex2f(94.4f,28.7f);
    glVertex2f(94.4f,27.6f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(95.4f,27.6f);
    glVertex2f(95.4f,28.6f);
    glVertex2f(96.4f,28.6f);
    glVertex2f(96.4f,27.6f);
    glEnd();

    ////1.3
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.25f, 0.91f);
    glVertex2f(86.0f,14.3f);
    glVertex2f(86.0f,18.0f);
    glVertex2f(96.4f,18.0f);
    glVertex2f(96.4f,14.3f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(87.4f,15.0f);
    glVertex2f(87.4f,17.4f);
    glVertex2f(88.9f,17.4f);
    glVertex2f(88.9f,15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(89.4f,15.0f);
    glVertex2f(89.4f,17.4f);
    glVertex2f(90.9f,17.4f);
    glVertex2f(90.9f,15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(86.9f,18.0f);
    glVertex2f(86.9f,19.1f);
    glVertex2f(92.0f,19.1f);
    glVertex2f(92.0f,18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(93.4f,18.0f);
    glVertex2f(93.4f,19.1f);
    glVertex2f(94.4f,19.1f);
    glVertex2f(94.4f,18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(95.4f,18.0f);
    glVertex2f(95.4f,19.1f);
    glVertex2f(96.4f,19.1f);
    glVertex2f(96.4f,18.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(86.9f,13.2f);
    glVertex2f(86.9f,14.3f);
    glVertex2f(92.0f,14.3f);
    glVertex2f(92.0f,13.2f);
    glEnd();

    //2nd
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.25f, 0.91f);
    glVertex2f(78.5f,16.0f);
    glVertex2f(78.5f,27.5f);
    glVertex2f(84.0f,27.5f);
    glVertex2f(84.0f,16.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(78.0f,24.5f);
    glVertex2f(78.0f,25.5f);
    glVertex2f(83.0f,25.5f);
    glVertex2f(83.0f,24.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(78.0f,22.5f);
    glVertex2f(78.0f,23.5f);
    glVertex2f(83.0f,23.5f);
    glVertex2f(83.0f,22.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(78.0f,20.5f);
    glVertex2f(78.0f,21.5f);
    glVertex2f(83.0f,21.5f);
    glVertex2f(83.0f,20.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(78.0f,18.5f);
    glVertex2f(78.0f,19.5f);
    glVertex2f(83.0f,19.5f);
    glVertex2f(83.0f,18.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(78.0f,16.5f);
    glVertex2f(78.0f,17.5f);
    glVertex2f(83.0f,17.5f);
    glVertex2f(83.0f,16.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.7f,14.0f);
    glVertex2f(78.7f,16.0f);
    glVertex2f(81.0f,16.0f);
    glVertex2f(81.0f,14.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.87f, 0.98f, 0.75f);
    glVertex2f(79.2f,14.5f);
    glVertex2f(79.2f,15.5f);
    glVertex2f(80.5f,15.5f);
    glVertex2f(80.5f,14.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(81.5f,13.0f);
    glVertex2f(81.5f,16.0f);
    glVertex2f(83.5f,16.0f);
    glVertex2f(83.5f,13.0f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(82.0f,13.5f);
    glVertex2f(82.0f,15.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(82.5f,13.5f);
    glVertex2f(82.5f,15.5f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(83.0f,13.5f);
    glVertex2f(83.0f,15.5f);
    glEnd();

    //3rd

    glBegin(GL_QUADS);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(79.5f,18.5f);
    glVertex2f(79.5f,28.5f);
    glVertex2f(86.0f,28.5f);
    glVertex2f(86.0f,18.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.64f, 0.72f);
    glVertex2f(79.0f,19.5f);
    glVertex2f(79.0f,26.0f);
    glVertex2f(84.0f,26.0f);
    glVertex2f(84.0f,19.5f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.5f,21.0f);
    glVertex2f(80.5f,21.0f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.5f,22.0f);
    glVertex2f(80.5f,22.0f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.5f,23.0f);
    glVertex2f(80.5f,23.0f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.5f,24.0f);
    glVertex2f(80.5f,24.0f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.85f, 0.74f, 0.09f);
    glVertex2f(78.5f,25.0f);
    glVertex2f(80.5f,25.0f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(81.0f,20.5f);
    glVertex2f(81.0f,25.5f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(82.0f,20.5f);
    glVertex2f(82.0f,25.5f);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.87f, 0.98f, 1.00f);
    glVertex2f(83.0f,20.5f);
    glVertex2f(83.0f,25.5f);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(85.0f,19.2f);
    glVertex2f(85.0f,28.5f);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.49f, 0.25f, 0.73f);
    glVertex2f(79.5f,19.5f);
    glVertex2f(85.0f,19.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.53f, 0.53f);
    glVertex2f(82.5f,26.5f);
    glVertex2f(82.5f,28.5f);
    glVertex2f(84.5f,28.5f);
    glVertex2f(84.5f,26.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(82.5f,26.5f);
    glVertex2f(84.5f,26.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(82.5f,27.0f);
    glVertex2f(84.5f,27.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(82.5f,27.5f);
    glVertex2f(84.5f,27.5f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(82.5f,28.0f);
    glVertex2f(84.5f,28.0f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(82.5f,28.4f);
    glVertex2f(84.5f,28.4f);
    glEnd();

}

void sideBuilding3(){
    glPushMatrix();
        glTranslatef(-101.0f,35.0f,0.0f);
        glScaled(1.3f,1.3f,0.0f);
        sideBuilding2();
    glPopMatrix();
}

void sideBuilding5(){
    glPushMatrix();
        glTranslatef(35.0f,0.0f,0.0f);
        //glScaled(1.3f,1.3f,0.0f);
        sideBuilding2();
    glPopMatrix();
}

void sideBuilding4(){
    glPushMatrix();
        glTranslatef(-102.0f,35.0f,0.0f);
        //glScaled(1.3f,1.3f,0.0f);
        sideBuilding();
    glPopMatrix();
}

void sideBuilding6(){
    glPushMatrix();
        glTranslatef(-15.0f,0.0f,0.0f);
        //glScaled(1.3f,1.3f,0.0f);
        sideBuilding();
    glPopMatrix();
}

void sideBuilding7(){
    glPushMatrix();
        glTranslatef(-61.0f,20.0f,0.0f);
        //glScaled(1.3f,1.3f,0.0f);
        sideBuilding1();
    glPopMatrix();
}

void sideBuilding8(){
    glPushMatrix();
        glTranslatef(-75.0f,15.0f,0.0f);
        glScaled(0.7f,0.7f,0.0f);
        sideBuilding();
    glPopMatrix();
}

void sideBuilding9(){
    glPushMatrix();
        glTranslatef(-47.0f,5.0f,0.0f);
        glScaled(0.6f,0.6f,0.0f);
        sideBuilding2();
    glPopMatrix();
}

//far Tree
int farTreeF(float x,float y, float r, float r1){
    int i;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.49f, 0.78f, 0.26f);
    glVertex2f(x,y);

    for(i=0; i<=triangleAmount;i++)
    {
        glVertex2f(
            x+(r*cos(i*twicePi/triangleAmount)),
            y+(r1*sin(i*twicePi/triangleAmount))
        );
    }

    glEnd();
}

void farTree(){
    farTreeF(1.8f,16.5f,5,4);
    farTreeF(7.3f,17.8f,2,3);
    farTreeF(9.3f,18.0f,2,2.3);
    farTreeF(11.3f,18.4f,1.5,2);
    farTreeF(14.3f,18.4f,2,1.5);
    farTreeF(18.3f,18.0f,3,2.5);
    farTreeF(20.3f,17.8f,2,1.5);
    farTreeF(24.1f,17.8f,2.5,2);
    farTreeF(28.1f,16.8f,4,3);
    farTreeF(32.1f,17.8f,2,1.5);
    farTreeF(34.1f,18.5f,2,1.5);
    farTreeF(37.1f,19.0f,2,1.5);

    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.78f, 0.26f);
    glVertex2f(0.0f,18.5f);
    glVertex2f(0.0f,20.8f);
    glVertex2f(40.5f,20.8f);
    glVertex2f(39.0f,18.5f);
    glEnd();
}

void farTrees(){
    glPushMatrix();
        farTree();
        glTranslatef(35.0f,0.0f,0.0f);
        farTree();
        glTranslatef(32.0f,0.0f,0.0f);
        farTree();
        glTranslatef(30.0f,0.0f,0.0f);
        farTree();
    glPopMatrix();
}

void mudBacground(){
    glBegin(GL_QUADS);
    glColor3f(0.52f, 0.48f, 0.45f);
    glVertex2f(0.0f,20.8f);
    glVertex2f(0.0f,73.0f);
    glVertex2f(130.0f,73.0f);
    glVertex2f(130.0f,20.8f);
    glEnd();
}

void swing(){
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(128.3f,53.4f);
    glVertex2f(128.3f,45.4f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(121.3f,53.4f);
    glVertex2f(121.3f,45.4f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(128.3f,45.7f);
    glVertex2f(121.3f,45.7f);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(126.3f,51.7f);
    glVertex2f(123.3f,51.7f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(126.3f,51.4f);
    glVertex2f(127.0f,45.4f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.61f, 0.82f, 0.84f);
    glVertex2f(123.3f,51.4f);
    glVertex2f(122.0f,45.4f);
    glEnd();
}

void branch(){

    glBegin(GL_QUADS);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(79.0f,62.6f);
    glVertex2f(82.5f,63.9f);
    glVertex2f(92.0f,58.9f);
    glVertex2f(88.5f,57.9f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(79.5f,62.6f);
    glVertex2f(79.5f,65.6f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(91.5f,58.9f);
    glVertex2f(91.5f,61.9f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(82.5f,63.8f);
    glVertex2f(82.5f,66.8f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(79.5f,62.6f);
    glVertex2f(79.5f,59.6f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(88.5f,54.9f);
    glVertex2f(88.5f,58.0f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(88.5f,54.9f);
    glVertex2f(79.5f,59.6f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(88.5f,55.9f);
    glVertex2f(79.5f,60.6f);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.60f, 0.37f, 0.17f);
    glVertex2f(88.5f,56.9f);
    glVertex2f(79.5f,61.6f);
    glEnd();
}

void pFront(){
    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.29f, 0.31f);
    glVertex2f(48.0f,44.0f);
    glVertex2f(64.1f,60.2f);
    glVertex2f(98.9f,45.0f);
    glVertex2f(80.6f,35.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.50f, 1.00f);
    glVertex2f(53.0f,45.0f);
    glVertex2f(64.7f,56.6f);
    glVertex2f(92.9f,45.0f);
    glVertex2f(78.6f,37.5f);
    glEnd();
}

void myInit(){
    glClearColor(0.0f,0.5f, 1.0f, 1.0f);
    glOrtho(0.0, 130.0, 73.0, 0.0, -1.0, 1.0);
    //gluOrtho2D(0.0, 130.0, 73.0, 0.0);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
        glTranslatef(0.0f,sunPosition, 0.0f);
        sun();
    glPopMatrix();

    cloud();



    mudBacground();

    footPath();
    footPath2();


    Road();

    glPushMatrix();
        glTranslatef(car1Position,car1Position1, 0.0f);
        glScalef(car1Scale,car1Scale,0.0f);
        Car1();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(car2Position,car2Position1, 0.0f);
        glScalef(car2Scale,car2Scale,0.0f);
        Car2();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(car3Position,car3Position1, 0.0f);
        glScalef(car3Scale,car3Scale,0.0f);
        Car3();
    glPopMatrix();



    cloud();

    Ground();

    grassS();

    swing();

    branch();

    pFront();


    glPushMatrix();
        glTranslatef(tank2Position,0.0f, 0.0f);
        tank2();
    glPopMatrix();

    Fire1();

    farBuilding();
    farBuilding1();
    farBuilding2();
    farBuilding3();
    farBuilding4();
    farBuilding5();
    farBuilding6();

    farTrees();

    sideBuilding9();
    pTree();
    Tree();
    Lamp();

    Tree6();
    Tree1();
    Tree2();
    Tree3();
    Tree5();
    Tree4();
    Tree7();
    Tree8();
    Tree9();
    pTree1();

    sideBuilding1();

    sideBuilding8();
    sideBuilding7();
    sideBuilding6();
    sideBuilding4();
    sideBuilding3();
    sideBuilding();
    sideBuilding2();
    sideBuilding5();

    //Nbuilding();
    building();
    //building1();

    pTree();

    glPushMatrix();
        glTranslatef(tankPosition,0.0f, 0.0f);
        tank();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(heliPosition,0.0f, 0.0f);
        heli();
    glPopMatrix();

    Fire();
    Fire2();


    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key=='p')
    {
        sunset(0.2f);
        glutPostRedisplay();
    }

    else if(key=='l')
    {
        sunset2(0.0f);
        glutPostRedisplay();
    }

    else if(key=='r')
    {
        tankStart(0.2f,1.0);
        glutPostRedisplay();
    }

    else if(key=='u')
    {
        tankStop(0.0f,0.0);
        glutPostRedisplay();
    }

    else if(key=='s')
    {
        tankStart(-0.2f,-1.0);
        glutPostRedisplay();
    }

    else if(key=='i')
    {
        heliStart(-0.3f);
        glutPostRedisplay();
    }

    else if(key=='a')
    {
        heliStop(0.0f);
        glutPostRedisplay();
    }

    else if(key=='q')
    {
        rocketStart(-4.0,-4.0);
        allCarStop(0.0f,0.0f,0.0f);
        glutPostRedisplay();
    }

    else if(key=='w')
    {
        HrocketStart(4.0,0.1);
        allCarStop(0.0f,0.0f,0.0f);
        glutPostRedisplay();
    }

    else if(key=='k')
    {
        tank2Stop(0.0f,0.0);
        tank2Start(-0.2f,-1.0);
        glutPostRedisplay();
    }

    else if(key=='y')
    {
        tank2Stop(0.0f,0.0);
        glutPostRedisplay();
    }

    else if(key=='e')
    {
        tank2Start(0.2f,1.0);
        //tank2Stop(0.0f,0.0);
        glutPostRedisplay();
    }

    else if(key=='v')
    {
        rocket2Start(4.0,1.5);
        allCarStop(0.0f,0.0f,0.0f);
        glutPostRedisplay();
    }
}

void mouse(int button,int state,int x,int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            heliStartInc();
        break;

        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
            heliStartDc();
        break;

        default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1300, 730);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Russia_Ukraine War(KYIV under attack)");
    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(100, updateCar1, 0);
    glutTimerFunc(100, updates, 0);
    glutTimerFunc(100, updatesT, 0);
    glutTimerFunc(100, updatesT2, 0);
    glutTimerFunc(100, updateCar2, 0);
    glutTimerFunc(100, updateCar3, 0);
    glutTimerFunc(100, updateCloud1, 0);
    glutTimerFunc(100, updateCloud2, 0);
    glutTimerFunc(100, updateCloud3, 0);
    glutTimerFunc(100, updateCloud4, 0);
    glutTimerFunc(100, updateCloud5, 0);
    glutTimerFunc(100, updateSun, 0);
    glutTimerFunc(100, updateTank, 0);
    glutTimerFunc(100, updateTank2, 0);
    glutTimerFunc(100, updateHeli, 0);
    glutTimerFunc(100, updateRocket, 5);
    glutTimerFunc(100, updateRocket2, 5);
    glutTimerFunc(100, updateHeliRocket, 5);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
