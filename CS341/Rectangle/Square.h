class Square: public Rectangle {
	private:
		int side;
	public:
		Square();
		Square(int x) {side = x;}
		
		int area();
		int perm();
};//end class Square