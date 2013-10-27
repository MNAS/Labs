package net.mksat.mnasoft.p0010;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;

public class Graph extends Activity {
	private static final String TAG = "Graph";

	private MyView myView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		Log.d(TAG, "onCreate");

		myView = new MyView(this);
		setContentView(myView);
		myView.requestFocus();

		// setContentView(R.layout.activity_graph);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.graph, menu);
		return true;
	}
}
