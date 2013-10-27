package net.mksat.mnasoft.p0010;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
//import android.graphics.Path;
import android.view.View;

public class MyView extends View {
//	private static final String TAG = "Graph";
	private final Graph gaphic;
	
	private double x_min=-5.0;
	private double x_max=5.0;
	
	private double y_min;
	private double y_max;
	
	private int x_clearence=50;
	private int y_clearence=50;
	
	private int n_points = 100;
	double ax[] = new double[n_points+1];
	double ay[] = new double[n_points+1];
	
	Paint background = new Paint();
	Paint foreground = new Paint();

	public MyView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		this.gaphic = (Graph) context;
		setFocusable(true);
		setFocusableInTouchMode(true);

		// setId(ID);
	}

	public Graph getGaphic() {
		return gaphic;
	}

	@Override
	protected void onDraw(Canvas canvas) {
		// Draw the background...

		
		y_min = Double.POSITIVE_INFINITY;
		y_max = Double.NEGATIVE_INFINITY;
		for (int i = 0; i <= n_points; i++) {
			ax[i] = x_min + (x_max - x_min) * i / n_points;
			ay[i] = culcFunc(ax[i]);
			if (ay[i] < y_min)
				y_min = ay[i];
			if (ay[i] > y_max)
				y_max = ay[i];
		}
		

		// pth.moveTo((float)ax[0],(float)ay[0]);
		// for(int i=1; i<n_points ; i++)
		// pth.lineTo((float)ax[i], (float)ay[i]);

		background.setColor(Color.BLUE);
		foreground.setColor(Color.YELLOW);

		canvas.drawRect(0, 0, getWidth(), getHeight(), background);
//		canvas.drawPath(pth, foreground);
//		canvas.drawLine(0, 0, getWidth(), getHeight(), foreground);
		
		for (int i = 0; i < n_points; i++) {
			canvas.drawLine((float)X_transform(ax[i]) , (float) Y_transform(ay[i]),
					(float)X_transform(ax[i+1]) , (float) Y_transform(ay[i+1]), 
					foreground);
		}

	}

	private double culcFunc(double x) {
		double res;
//		res = Math.log10((x * x * x - 1.2) / (x * x + Math.cos(x)));
		res = (x * x * x);
		return res;

	}

	private double X_transform(double x) {
		double res;
		double X1_X0 = getWidth()-2*x_clearence;
		double x1_x0 = x_max - x_min;
		res = X1_X0 / x1_x0 * (x - x_min)+x_clearence;
		return res;
	}
	
	private double Y_transform(double y) {
		double res;
		double Y1_Y0 = getHeight()-2*+x_clearence;
		double y1_y0 = -(y_max - y_min);
		res = Y1_Y0 / y1_y0 * (y - y_max)+y_clearence;
		return res;
	}

}
