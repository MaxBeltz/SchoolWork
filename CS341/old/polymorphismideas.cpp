//this code will not run as we are not fillin in the details

//we will have a base shape class, from which rectangle and share will inherit as an inheritance chain. We will also inherit triangle from shape directly

//the shape base class has a virtual function called area that each inherited class redefines

//Rectangle adds another virtual function to conpute its diagonal which square inherits
int main (){
	Rectangle r(3, 12);
	Square s(12);
	Triangle t(1,2,5);
		
	Shape * shape1 = &r;
	Shape * shape2 = &s;
	Shape * shape3 = &t;
	
	//each virtual area function will execute according to its shape
	shape1->area();
	shape2->area();
	shape3->area();
	
	Rectangle * rect1 = &r;
	Rectangle * rect2 = &s;
	
	//this will not work because the shape base class does not have the diagonal function
	shape1->diagonal();
	shape2->diagonal();
	
	//this will work
	rect1->diagonal();
	rect2->diagonal();
	
	return 0;
}