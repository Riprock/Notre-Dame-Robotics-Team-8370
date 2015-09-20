/* auto
 * team th_
 */

task auto()
{
	wait1Msec(2000);
	
	int threshold = 505;
	
	
	clearTimer(T1)
		
		while(time1[T1] < 10000)
	{
		if(SensorValue(lineTracker) < threshold)
		{
			
			motor[leftMotor] = 63;
			motor[rightMotor] = 0;
		}
		wait(5)
		{
			motor[leftMotor]  = 0;
			motor[rightMotor]  = 63;
		}
		
		
		
		if(SensorValue(lineTracker) > threshold)
		{
			
			motor[leftMotor] = 0;
			motor[rightMotor] = 63;
		}
		wait(5)
		{
			motor[leftMotor]  = 63;
			motor[rightMotor]  = 0;
		}
		
		
		
		if(SensorValue(lineTracker) > threshold)
		{
			
			motor[leftMotor] = 63;
			motor[rightMotor] = 63;
		}
		wait(5)
		{
			motor[leftMotor]  = 63;
			motor[rightMotor]  = 0;
		}
		
		
		
		if(SensorValue(lineTracker) > threshold)
		{
			
			motor[leftMotor] = 0;
			motor[rightMotor] = 63;
		}
		wait(5)
		{
			motor[leftMotor]  = 63;
			motor[rightMotor]  = 63;
		}
		
		
		
		if(SensorValue(lineTracker) > threshold)
		{
			
			motor[leftMotor] = 63;
			motor[rightMotor] = 0;
		}
		wait(5)
		{
			motor[leftMotor]  = 63;
			motor[rightMotor]  = 63;
		}
		
		
		
		if(SensorValue(lineTracker) > threshold)
		{
			
			motor[leftMotor] = 63;
			motor[rightMotor] = 63;
		}
		wait(5)
		{
			motor[leftMotor]  = 0;
			motor[rightMotor]  = 63;
		}
		else
		{
			wait(999999999999999999)
		}
	}
}

end



	
task drive()	
{
	
	
	
	
}
