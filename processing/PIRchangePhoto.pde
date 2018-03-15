···
import processing.serial.*;
Serial myPort;
int numphotos=2;//设置图片总数
//int whichphoto=0;//决定当前展示的是哪张图片
PImage[] photos=new PImage[numphotos];
int count=0;
void setup(){
  noCursor();
  fullScreen(2);
  //size(640,480);
  myPort=new Serial(this,Serial.list()[0],115200);
  myPort.bufferUntil('\n');
  background(0);
  for(int i=0;i<numphotos;i++){
    photos[i]=loadImage(i+".jpg");
  }
  
}

void draw(){
  if(myPort.available() > 0){
    print(myPort.readString());
    count=20;
  }else{
    print("nothing");
  }
  if(count>=0){
    image(photos[0],width/8,0,width*3/4,height);
    count--;
  }else{
    image(photos[1],width/8,0,width*3/4,height);
  }
}
···
