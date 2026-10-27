/*This the project by our Team for The course CSE 232s "Fundamentals of Computer Programming" for Semester Spring 26
Team Members:
Ahmed Ali Ahmed             2400322
Safey Eldeen Samy Zidan      2400396
Amr Waleed Bakr             2400588
Omar Mamdouh Mohmmed        2400990
Ahmed Tamer Mahmoud         2401709

Supervised by:
Dr. Basem Amin Hamed
Dr. Mohamed Mahmoud Hamdy
*/
#include <iostream>
#include <cmath>
using namespace std;

class motor
{
private :
      // Defining the Attributes of the motor
    float Torque;
    float speed;
    float Mass;
    float d;
    float Width;
    float cost;
public :
    motor(float T,float RPM,float Ms,float Di,float Wi){
 float  setTorque(T); // unit: micro Nm
 float  setspeed(RPM); // unit: rpm
 float  setMass(Ms); // unit: gram
  float setDiameter(Di); // unit: mm
   float setWidth(Wi); // unit: mm
    };

  // Functions for accessing data
   float getTorque(){return Torque;};
    float getSpeed(){return speed;};
    float getMass(){return Mass;};
    float getDiameter(){return Diameter;};
    float getWidth(){return Width;};
    float calc_cost(){return cost;};
};


// Defining a Database of some materials to be avaliable for the user during selection
class gearbox
{
private :
    // Defining the Attributes of the Gearbox
    float GearRatio;
    float Efficiency;
    float Mass;
    float Diameter;
    float Width;
    float cost;
public:
     // Defining function to add info
  gearbox(float GR,float Ef,float Ms,float Di,float Wi){
  GearRatio=GR;
  Efficiency=Ef; // unit: percentage
  Mass=Ms; // unit: gram
  Diameter=Di; // unit: mm
  Width=Wi; // unit: mm
  };
   // Functions for accessing data
   float getGearRatio(){return GearRatio;};
   float getEfficiency(){return Efficiency;};
    float getMass(){return Mass;};
    float getDiameter(){return Diameter;};
    float getWidth(){return Width;};
    float calc_cost(){return cost;};
};


class Materials
{
private:
    // Defining the Attributes of the materials
    float yield_strength;
    float density;
    string name;

public:
    // Defining function to add materials
    Materials(float ys, float rue, string nam){
    yield_strength = ys;
    name = nam ;
    density = rue ;}
    // Functions for accessing data
    string getname() {return name ;}
    float getdensity() {return density;}
    float getstrength() {return yield_strength;}

};
//Functions declaration
float ml_circular(float r,float l,float densityy);//--------------------->>>> Link mass for circular cross section
float ml_rectangular(float l,float w,float h,float densityy);//--------------------->>>> Link mass for rectangular cross section
float Bending_Moment(float ml,float mp,float l,float g_g,float alpha_max);//--------------------->>>> Bending Moment
float Moment_of_inertia_circular(float r);//--------------------->>>> moment of inertia for circular cross section
float Moment_of_inertia_rectangular(float w,float h);//--------------------->>>> moment of inertia for rectangular cross section
float Sigma_circular(float bm,float r,float moi);//--------------------->>>> Maximum stress for circular cross section
float Sigma_rectangular(float bm,float h,float moi);//--------------------->>>> Maximum stress for rectangular cross section
float Torque_req (float Ml,float Mp,float L,float Amax);//--------------------->>>> Calculate Required Torque

//new by omar

float Torque_Output (float T_motor, float Ratio , float efficiency );
float Speed_Output (float Speed_motor, float Ratio2  );

// The Main Program
int main (){

// defining variables outside statements

float radius,length,width,height,g=9.81,option,sel,stress,temp=1,mass_link;
string temp_2;

// Selecting Cross Section
cout<<"Enter any value to start\n";
cin>>temp_2;
do{
        cin.clear();cin.ignore();
cout << "\nEnter the cross section shape \nwhether circular Enter 1 \nor rectangular Enter 2 : \n \n " ;
cin >> option;
if(cin.fail()==1 || (option !=1 && option !=2)) cout<<"Invail input, Try Again.\n";
}while(cin.fail()==1 || (option !=1 && option !=2));


// Acquiring the user for the initial link dimensions
 if (option == 1){
    cout << "\nEnter the radius of the link in cm : \n\n " ;
    cin >> radius ;
    cout << "\nEnter the length of the link in cm : \n\n " ;
    cin >> length ;}
else if (option ==2){
    cout << "\nEnter the length of the link in cm : \n\n " ;
    cin >> length ;
    cout << "\nEnter the width of the link in cm : \n\n " ;
    cin >> width ;
    cout << "\nEnter the height of the link in cm : \n\n " ;
    cin >> height ;}

// Adding Materials, Creating objects, predefining database
Materials first(130, 7.3, "Cast Iron");
Materials second(130, 8.94, "Copper-Nickel");
Materials third(200, 8.73, "Brass");
Materials fourth(241, 2.7, "Aluminum");
Materials fifth(247, 7.58, "Steel");
Materials sixth(72, 1.16, "Acrylic");
Materials seventh(70, 8.92, "Copper");
Materials eighth(275, 7.86, "Stainless Steel");
Materials nineth(941, 19.25, "Tungsten");

// Displaying the name of the available Materials for the user
cout <<"\n\nBelow is a list of the available materials : \n\n " <<"1- "<< first.getname() << "\n " ;
cout <<"2- "<< second.getname() << "\n " ;
cout <<"3- "<< third.getname() << "\n " ;
cout <<"4- "<< fourth.getname() << "\n " ;
cout <<"5- "<< fifth.getname() << "\n " ;
cout <<"6- "<< sixth.getname() << "\n " ;
cout <<"7- "<< seventh.getname() << "\n " ;
cout <<"8- "<< eighth.getname() << "\n " ;
cout <<"9- "<< nineth.getname() << "\n " ;
cout <<"0- add new material \n";

// Defining the variables of materials properties
float Density ; float Yield; string Material ;

// Selecting Material Process
cout << "\nSelect an appropriate material by entering its number or type 0 to add new material :  \n\n " ;
cin >> sel ;

if ( sel==1 ){
    Material = first.getname();
    Yield = first.getstrength();
    Density = first.getdensity();}
else if ( sel==2 ){
    Material = second.getname();
    Yield = second.getstrength();
    Density = second.getdensity();}
else if ( sel==3 ){
    Material = third.getname();
    Yield = third.getstrength();
    Density = third.getdensity();}
else if ( sel==4 ){
    Material = fourth.getname();
    Yield = fourth.getstrength();
    Density = fourth.getdensity();}
else if ( sel==5 ){
    Material = fifth.getname();
    Yield = fifth.getstrength();
    Density = fifth.getdensity();}
else if (sel==6){
    Material = sixth.getname();
    Yield = sixth.getstrength();
    Density = sixth.getdensity();}
    else if ( sel==7 ){
    Material = seventh.getname();
    Yield = seventh.getstrength();
    Density = seventh.getdensity();}
else if ( sel==8 ){
    Material = eighth.getname();
    Yield = eighth.getstrength();
    Density = eighth.getdensity();}
else if (sel==9){
    Material = nineth.getname();
    Yield = nineth.getstrength();
    Density = nineth.getdensity();}
else if (sel==0) {
    cout << "\nEnter The Material Name : " ; cin >> Material ;
    cout << "\nEnter The Material Yield Strength : " ; cin >> Yield ;
    cout << "\nEnter The Material Density : " ; cin >> Density ;}
else {cout << "Error";
     return 0;}

// Choosing mass that is needed to be held by the robotic arm (payload)
 float mass ;
 cout << "\nEnter the mass of the object wanted to be held in KG : \n\n " ;
 cin >> mass ;

// Getting the maximum angular acceleration
float ang_acc ;
cout << "\nEnter the maximum angular acceleration required by the link in radians per second square : \n\n ";
cin >> ang_acc ;
cout<<"yield = "<<Yield<<endl;
while(temp==1){

//calculations for circular cross section
if (option ==2){
    mass_link=ml_rectangular(length,width,height,Density);
    Bending_Moment(ml_rectangular(length,width,height,Density),mass,length,g,ang_acc);
    Moment_of_inertia_rectangular(width,height);
    stress = Sigma_rectangular(Bending_Moment(ml_rectangular(length,width,height,Density),mass,length,g,ang_acc),height,Moment_of_inertia_rectangular(width,height));}

 //calculations for rectangular cross section
else {
    mass_link=ml_circular(radius,length,Density);
    Bending_Moment(ml_circular(radius,length,Density),mass,length,g,ang_acc);
    Moment_of_inertia_circular(radius);
    stress = Sigma_circular(Bending_Moment(ml_circular(radius,length,Density),mass,length,g,ang_acc),radius,Moment_of_inertia_circular(radius));}
cout<<stress<<endl;


//if yield is larger than yield strength
if(stress>=Yield){

if(option == 1 ){
    //length = length + length /20;
    radius = radius + radius /5;
    continue;
}

else {
   // length = length + length /20;
    width = width + width /20;
    height = height + height /20;
    continue;
}

}
//if yield is smaller than yield strength
if(stress<(Yield - 3)){
    if(option == 1 ){
    //length = length - length /100;
    radius = radius - radius /100;
    continue;
}
else {
    //length = length - length /100;
    width = width - width /100;
    height = height - height /100;
    continue;
}

}
break;
}
cout <<"Stress= "<<stress<<"\n" ;
if(option ==1) cout<<"Length = "<<length <<"\nRadius ="<<radius<<"\n";
else cout<<"Length = "<<length<<"\nHeight = "<<height<<"\nWidth ="<<width<<"\n";
cout <<"mass of link = " <<mass_link<<"kg\n";
// Adding Gear box info

gearbox one(15,85,2800,15,90);
gearbox two(19,81,23,16,30.85);
gearbox three(14,70,55,22,44.25);
gearbox four(18,75,162,32,57.4);
gearbox five(370,65,31,16,38.05);
gearbox six(246,60,226,32,70.8);
gearbox seven(318,60,226,32,70.8);
gearbox eight(243,65,19,12,41.85);

// Adding motor info

motor I(33.1,8530,32,22,1);
motor  II (44.5,14000,110,22,1);
motor III (46,12300,110,22,1);
motor IV (48.2,9840,120,22,1);
motor V (102,7740,71,32,1);
motor VI  (115,10400,71,32,1);
motor VII(171,7070,106,32,1);
motor VIII(186,5110,170,32,1);


//Torque required calculation
//float T=Torque_req(mass_link,mass,length,,ang_acc);
float T=Bending_Moment(mass_link,mass,length,9.81,ang_acc);
cout <<"Torque required is "<<T<<"\n";

//new by omar

float T_motor , Ratio , efficiency ;
cout << "Please enter Torque of motor & Ratio & Efficiency respectively \n";
cin>>T_motor>>Ratio>>efficiency;
cout<< " Torque output is " << Torque_Output ( T_motor, Ratio ,  efficiency )<< "\n";

float Speed_motor , Ratio2 ;
cout<< "Please enter speed of motor & ratio respectively \n";
cin>> Speed_motor >> Ratio2 ;
cout<< " Speed output is " <<Speed_Output ( Speed_motor, Ratio2)<<"\n";

float Speed_required;
cout << "Enter required output speed (rpm): ";
cin >> Speed_required;








return 0 ;
// length,height,width,radius in cm-----g in m/sec^2---------Masses in Kg---------Bending moment i n N.mm------Moment of inertia in mm^4------sigma in MPa
}
//Functions definition
float ml_circular(float r,float l,float densityy){
    float link_mass = (densityy*M_PI*pow(r,2)*l)*0.001;    //--------------------->>>> Link mass for circular cross section
    return(link_mass);}

float ml_rectangular(float l,float w,float h,float densityy){
    float link_mass = (densityy*l*w*h)*0.001;                         //--------------------->>>> Link mass for rectangular cross section
    return(link_mass);}

float Bending_Moment(float ml,float mp,float l,float g_g,float alpha_max){
    float BM= (ml*g_g*(l*0.01/2)+(mp*g_g*l*0.01)+(ml*pow(l*0.01/2,2)*alpha_max+mp*pow(l*0.01,2)*alpha_max));//--------------------->>>> Bending Moment
    return (BM);}

float Moment_of_inertia_circular(float r){
    float MoI= ((M_PI*pow(r*10,4))/4) ;         //--------------------->>>> moment of inertia for circular cross section
    return (MoI);}

float Moment_of_inertia_rectangular(float w,float h){
    float MoI = ((w*10*pow(h*10,3))/12);                      //--------------------->>>> moment of inertia for rectangular cross section
    return(MoI);}

float Sigma_circular(float bm,float r,float moi){
    float sigma;
    sigma = (bm*r*10000)/moi;                      //--------------------->>>> Maximum stress for circular cross section
    return(sigma);}

float Sigma_rectangular(float bm,float h,float moi){
    float sigma;
    sigma = (bm*h*10000)/(2*moi);                     //--------------------->>>> Maximum stress for rectangular cross section
    return(sigma);}
float Torque_req (float Ml,float Mp,float L,float Amax){

int T=Ml*9.81*(L*0.01/2)+Mp*9.81*L+(Ml*pow(L*0.01/2,2)*Amax+Mp*pow(L*0.01,2)*Amax);

return T;

}


// new by omar

float Torque_Output (float T_motor, float Ratio , float efficiency )
{
   return T_motor * Ratio * efficiency;

}
float Speed_Output (float Speed_motor, float Ratio2)
{
    return Speed_motor / Ratio2 ;
}




