// 0: Idle - no move currently active
// 1: Decelerating - approaching end of move
// 2: At_Max - moving at full speed
// 3: Accelerating - move starting
// speed=oneStepMove/stepDelay;
// speed= (60)mm/s=(60)*1000*1000mm/us
// speed= (60)*1000*1000*steppermm mm/us
// speed= (60)*1000*1000*100 steps/us
delayNow = 1 / present_speed; // us/step
int state;
void smoothPeriodMove(long steps, unsigned int period_us, int accellerate)
{
    //init
    const int Accelerating = 1;
    const int At_Max = 2;
    const int Decelerating = 3;
    int state = Accelerating;
    long total_move_count = steps;
    long midpoint = total_move_count / 2;
    float present_speed = 1;
    float acceleration = 1;
    long step_count = 0;
    int delayNow;
    max_speed = 1 / period_us;
    //loop
    while (step_count < total_move_count)
    {
        if (state == Accelerating)
        {
            present_speed = present_speed + acceleration;
            if (step_count == midpoint)
            {
                state = Decelerating;
            }
            else if (present_speed >= max_speed)
            {
                deceleration_start = total_move_count - step_count; //total move_count
                state = At_Max;
            }
            else
            {
                singleStep(delayNow);
            }
        }
        if (state == At_Max)
        {
            singleStep(delayNow);
            if (step_count == deceleration_start)
            {
                state = Decelerating;
            }
        }
        if (state == Decelerating)
        {
            present_speed = present_speed - acceleration;
            singleStep(delayNow);
        }
    }
}

singleStep(int usDelay);
calculate_deceleration_start;
