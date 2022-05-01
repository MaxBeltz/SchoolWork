import java.util.*;
import javax.swing.*;
 
public class boardSpace {

	// initialize party attributes
	int ownership = 0; // 0=unowned, 1=player owned, 2=ai owned
    JButton button = new JButton();
    JLabel label = new JLabel();
    int xval = 0;
    int yval = 0;
    int width = 0;
    int height = 0;

	public boardSpace(){
	}

	public void setButtonBounds(int x, int y, int w, int h){
        xval = x;
        yval = y;
        width = w;
        height = h;
        button.setBounds(xval, yval, width, height);
    }
}