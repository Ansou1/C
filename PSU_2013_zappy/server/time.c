/**
 * \file time.c
 * \brief time function.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * time function.
 *
 */

#include "zappy.h"

/**
 * \fn unsigned long get_current_time(void)
 * \brief get current time.
 *
 * \param void
 * \return unsigned long of time
 */

unsigned long get_current_time()
{
  struct timeval  tv;

  gettimeofday(&tv, NULL);
  return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * \fn unsigned long get_end_time(unsigned long start, const int t, const int period)
 * \brief get the end of time
 *
 * \param unsigned long start, const int t, const int period
 * \return unsigned long time
 */

unsigned long     get_end_time(unsigned long start, const int t, const int period)
{
  int interval;

  interval = t * 1000;
  interval /= period;
  start += interval;
  return (start);
}

