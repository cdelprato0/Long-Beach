import java.util.Random;
//x and y together capture the coordinates (squares really) of the snake as it
//has squares added to the front (when it advances) and removed from the rear 
//when it does not hit the apple).
ArrayList<Integer> x = new ArrayList <Integer>();
ArrayList<Integer> y = new ArrayList <Integer>();
//death snake
ArrayList<Integer> xDeath = new ArrayList <Integer>();
ArrayList<Integer> yDeath = new ArrayList <Integer>();
//Mine arrays
ArrayList<Integer> minex = new ArrayList<Integer>(); 
ArrayList<Integer> miney = new ArrayList<Integer>();  
//new mine position
int newminex = 0;
int newminey = 0;  
boolean newmine = false;
//Note that height and width are variables provided by the Processing environment
//so we don't want to override them in our code, hence w and h for variable names.
int w = 30;              //Width of the board
int h = 30;              //Height of the board
int bs = 20;             //block size
/* dx and dy are direction vectors.  The dir variable indexs into dx and dy
to control the direction the snake takes for the next advance. A value of 0
for dir means that dx is 0 and dy is 1, which sends the snake south.  1 sends
the snake north, 2 sends it east and 3 sends it west.  Remember that the 
coordinates increase as we move away from origin in the upper left corner of the 
screen.*/
int [] dx = {0, 0, 1, -1};
int [] dy = {1, -1, 0, 0};
int dir = 2;             //The next direction to take
int dirDeath = 2;        //the next direction of death snake
//Coordinates of the apple.  The snake gets longer each time it "eats" the apple.
int applex = 12;
int appley = 10;
boolean gameover = false;      //flag to show whether game is done or not.
int [] colors = {#266C1B, #E89E25, #2D3FDE, #C10A35, #EBF018, #000000};
final int initialFrameRate = 10;
void setup () {
  //600 = width * bs and height * bs.  If you change any of those three variables,
  //be sure to change the arguments to the size function accordingly.
  size (600, 600);            //size will only take literals, not variables
  x.add(5);              //Just a random starting position for the snake
  y.add(5);
  xDeath.add(7);
  yDeath.add(7);
  frameRate (initialFrameRate);              //start slow to make the game easier.
}
void draw () {
  background(255);            //make the background white
  //Create a grid pattern on the screen with vertical and horizontal lines
  for (int i = 0; i < width; i++) {
    line (i*bs, 0, i*bs, height);
  }
  for (int i = 0; i < height; i++) {
    line (0, i * bs, width, i * bs);
  }
  for (int i = 0; i < x.size(); i++) {      //draw the snake
//    fill(0, 255, 0);
    fill(colors[i % colors.length]);
    rect(x.get(i)*bs, y.get(i)*bs, bs, bs);
  }
  for (int i = 0; i < x.size(); i++) {      //draw the death snake
    fill(colors[5]);
    rect(xDeath.get(i)*bs, yDeath.get(i)*bs, bs, bs);
  }
  if (!gameover) {
    //draw the apple
    fill(255, 0, 0);
    rect(applex * bs, appley * bs, bs, bs);
    //draw the mines in for loop
    for(int i = 0; i < minex.size(); i++) 
    {
      fill(100,100,100);
      rect(minex.get(i) * bs, miney.get(i) * bs, bs, bs); 
    }
  }    
  if (!gameover) {
    if (frameCount % 5 == 0) {
      x.add(0, x.get(0) + dx[dir]);
      y.add(0, y.get(0) + dy[dir]);
      xDeath.add(0, xDeath.get(0) + dx[dirDeath]);
      yDeath.add(0, yDeath.get(0) + dy[dirDeath]);
  
      //Make sure that we do not run off the edge of the board
      if (x.get(0) < 0 || y.get(0) < 0 || x.get(0) >= w || y.get(0) >= h) {
        gameover = true;
      }
      if (frameCount % 5 == 0){
        boolean isInX = false;
        boolean isInY = false;
        for(int i = 1; i< x.size(); i++){
          if(x.get(i) == x.get(0)){
            isInX = true;
          }
          if(y.get(i) == y.get(0)){
             isInY = true; 
          }
          if(isInX == true & isInY == true){
            gameover = true; 
          }else{
            isInX = false;
            isInY = false;
          }
        }
        
        //Checks to see if the death snake gets the snake at any point on the snake
        boolean isDeathInX = false;
        boolean isDeathInY = false;
        for(int i = 1; i < x.size(); i++){
          if(xDeath.get(0) == x.get(i)){
            isDeathInX = true;
          }
          if(yDeath.get(0) == y.get(i)){
             isDeathInY = true; 
          }
          if(isDeathInX == true & isDeathInY == true){
            gameover = true; 
          }else{
            isDeathInX = false;
            isDeathInY = false;
          }
        }
        
        //the death snake doesnt run off the map
        if (xDeath.get(0) < 0 || yDeath.get(0) < 0 || xDeath.get(0) >= w || yDeath.get(0) >= h) {
          //if the snake is going west, it will now go east
          if(dirDeath == 3){
            dirDeath = 2;
          }
          //if the snake is going south, it will now go north
          else if(dirDeath == 1){
            dirDeath = 0;
          }
          //if the snake is going north, it will now go south
          else if(dirDeath == 0){
            dirDeath = 1;
          }
          //if the snake is going east, it will now go west
          else if(dirDeath == 2){
            dirDeath = 3;
          }
        }
        //if the death snake touches the snake
        if(x.get(0) == xDeath.get(0) && y.get(0) == yDeath.get(0)){
          gameover = true;
        }
        //See if we've hit the apple
        if(x.get(0) == applex && y.get(0) == appley) {
          applex = (int) random(0, w);      //Reposition the apple
          appley = (int) random(0, h);      //Don't make the snake shorter
          
        while(newmine != true){
        newminex = ((int) random(0, w));      //new mine coordinates
        newminey = ((int) random(0, h));
        if(applex != newminex && appley != newminey){
           if(!(minex.contains(newminex) && miney.contains(newminey)))
           {
            minex.add(newminex);
            miney.add(newminey);
           }
        }
        newmine = true;
        }
        newmine = false;
          frameRate(frameRate + frameRate / 10);
        } else {                      //Trim off the last element in the snake
          x.remove(x.size() - 1);
          y.remove(y.size() - 1);
        }
        for(int i = 0; i < minex.size(); i++) //For loop to check if we've hit the mine
        {
          if(x.get(0) == minex.get(i) && y.get(0) == miney.get(i)){
            gameover = true;
          }
        }
      }
    }
  }
  if (gameover) {
    fill (0);
    textSize(30);
    textAlign(CENTER);
    text("GAME OVER. Press space bar to resume.", width/2, height/2);
    if(keyPressed && key == ' ') {      //user wants to resume
      frameRate(initialFrameRate);      //start over with the speed of the game
      minex.clear();  //clear mine array
      miney.clear();
      minex.add(-1); //initial mine off grid
      miney.add(-1);
      x.clear();
      y.clear();
      x.add(5);
      y.add(5);
      xDeath.clear();
      yDeath.clear();
      xDeath.add(7);
      yDeath.add(7);
      gameover = false;
    }
  }
}


void keyPressed () {
  /*
  The "a" key starts the snake going left, "d" sends it right, "w" sends it up 
  and "s" sends it down.  The way to remember which is which is by their position
  on the qwerty keyboard.
  
  The dir variable is the index into the dx and dy vectors that we use when we add
  a new set of x,y coordinates to the front of the arraylist of points that represents
  our snake.
  */
  println("Key pressed is: " + key);
  int newdir = key == 's' ? 0 : (key == 'w' ? 1 : (key == 'd' ? 2 : (key == 'a' ? 3 : -1)));
  if(key == CODED){
      if(keyCode == UP){
        newdir = 1;
      }
      if(keyCode == DOWN){
        newdir = 0;
      }
      if(keyCode == RIGHT){
        newdir = 2;
      }
      if(keyCode == LEFT){
        newdir = 3;
      }
  }
  Random rand = new Random();
  
  if (newdir != -1){ 
  switch(newdir) //checks to prevent snake from turning around 180
    {
      case 0: 
        if(dir != 1) dir = newdir;
        break;
      case 1:
        if(dir != 0) dir = newdir;
        break;
      case 2:
        if(dir != 3) dir = newdir;
        break;
      case 3:
        if(dir != 2) dir = newdir;
        break;
      default:
      dir = newdir;
    }
    
    if(x.size() == 1) // if size is 1 it can still change direction
       dir = newdir;

    dirDeath = rand.nextInt(4);  //random direction
  }
}
