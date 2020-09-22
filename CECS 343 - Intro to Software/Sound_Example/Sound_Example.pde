// Note: this program runs only in the Processing IDE, not in the browser
//Borrowed from: https://funprogramming.org/99-Add-sounds-to-your-programs.html
//Demonstrates a bouncing ball and playing a .wav file each time that the ball
//"hits" a wall.

import ddf.minim.*;

class button{
  String label;
  int x;
  int y;
  int w;
  int h;
     
  public button(String lbl, int xpos, int ypos, int wid, int hei){
    label = lbl;
    x = xpos;
    y = ypos;
    w = wid;
    h = hei;
  }

  
  public boolean isInside(int mX, int mY){
      if((mX > 20 && mX < 120) && (mY > 20 && mY < 70) || (mX > 200 && mX < 320) && (mY > 20 && mY < 70) ){
        return true;
      }
    
    return false;
  }
  
  public void display(){
    fill(218);
    stroke(141);
    rect(x, y, w, h, 10);
    textAlign(CENTER, CENTER);
    fill(0);
    text(label, x + (w / 2), y + (h / 2));
  }
  
  public void press(){
    
  }
    
};

Minim minim;
AudioSample drum;
AudioSample cymbal;

button drum_Button;
button cymbal_Button;

int x = 130;
int y = 100;
int dx = 5;
int dy = 5;

void setup() {
  size(400, 300);
  fill(255, 0, 0);
  noStroke();
  smooth();

  minim = new Minim(this);
  drum = minim.loadSample("drum.wav", 2048);
  cymbal = minim.loadSample("cymbal.wav", 2048);
  drum_Button = new button("Drum", 20, 20, 100, 50);
  cymbal_Button = new button("Cymbal", 200, 20, 100, 50);
}
void draw() {
  background(255);
  
  drum_Button.display();
  cymbal_Button.display();

  if(mousePressed){
    if(drum_Button.isInside(mouseX, mouseY)){
      drum.trigger();
    }
    if(cymbal_Button.isInside(mouseX, mouseY)){
      cymbal.trigger();
    }
  }


}
void stop() {
  drum.close();
  cymbal.close();
  minim.stop();
  super.stop();
}
