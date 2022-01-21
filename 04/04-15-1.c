#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[1002];
  double timer = -1;
  long long delay = 0, posstart = -1, posend = -1, evflag = 0, tflag = 0, dflag = 0;
  fgets(s, 1002, stdin);
  while (1)
  {
    if (strstr(s, "End:") == s && s[4] == '\n')
    {
      printf("%s", s);
      break;
    }
    if (strstr(s, "[Events]") == s)
    {
      evflag = 1;
      printf("%s", s);
      fgets(s, 1002, stdin);
    }
    else if (strstr(s, "Timer:") == s && !evflag && !tflag)
    {
      double sum = 0;
      long long pos = 0;
      while (!(s[pos] >= '0' && s[pos] <= '9'))
        ++pos;
      while(s[pos] != '.')
      {
        sum *= 10;
        sum += (s[pos] - '0');
        ++pos;
      }
      ++pos;
      double pp = 0, mult = 0.01;
      while (s[pos] != '\n')
      {
        pp *= 10;
        pp += (double)(s[pos] - '0');
        ++pos;
      }
      pp *= mult;
      timer = sum + pp;
      char fs[1002] = "Timer: 100.00\n";
      tflag = 1;
      printf("%s", fs);
      fgets(s, 1002, stdin);
    }
    else if (strstr(s, "Delay:") == s && !evflag && !dflag)
    {
      long long h = 0, m = 0, sc = 0, hs = 0, mult = 1, pos = 0;
      while (!(s[pos] >= '0' && s[pos] <= '9'))
        ++pos;
      if (s[pos - 1] == '-')
        mult = -1;
      h = (s[pos] - '0');
      pos += 2;
      m += (s[pos] - '0') * 10 + (s[pos + 1] - '0');
      pos += 3;
      sc += (s[pos] - '0') * 10 + (s[pos + 1] - '0');
      pos += 3;
      hs += (s[pos] - '0') * 10 + (s[pos + 1] - '0');
      delay = hs + sc * 100 + m * 6000 + h * 360000;
      delay *= mult;
      dflag = 1;
      fgets(s, 1002, stdin);
    }
    else if (strstr(s, "Format:") == s)
    {
      long long dest_s = strstr(s, "Start") - s;
      long long dest_e = strstr(s, "End") - s;
      long long st = 0, se = 0;
      for (long long t = 0; t < dest_s; ++t)
      {
        if (s[t] == ',')
          ++st;
      }
      for (long long t = 0; t < dest_e; ++t)
      {
        if (s[t] == ',')
          ++se;
      }
      posstart = st, posend = se;
      printf("%s", s);
      fgets(s, 1002, stdin);
    }
    else if (strstr(s, "Dialogue:") == s)
    {
      long long ps = 0, pe = 0, cs = 0, ce = 0, ts = 0, te = 0, j = 0, m1 = 1, m2 = 1, fl1 = 0, fl2 = 0;
      while (cs < posstart)
      {
        if (s[j] == ',')
          ++cs;
        ++j;
      }
      if (posstart == 0)
        ps = 10;
      else
        ps = j;
      long long pps = ps;
      j = 0;
      while (ce < posend)
      {
        if (s[j] == ',')
          ++ce;
        ++j;
      }
      if (posend == 0)
        pe = 10;
      else
        pe = j;
      long long ppe = pe;
      if (s[ps] == '-')
      {
        m1 = -1, fl1 = 1, ++ps;
      }
      if (s[pe] == '-')
      {
        m2 = -1, fl2 = 1, ++pe;
      }
      if (s[ps] >= '0' && s[ps] <= '9' && s[pe] >= '0' && s[ps] <= '9')
      {
        ts += (s[ps] - '0') * 360000;
        ps += 2;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0')) * 6000;
        ps += 3;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0')) * 100;
        ps += 3;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0'));
        ts *= m1;

        te += (s[pe] - '0') * 360000;
        pe += 2;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0')) * 6000;
        pe += 3;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0')) * 100;
        pe += 3;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0'));
        te *= m2;
        if (timer > -1)
        {
          double tts = (double) ts * 100 / timer;
          double tte = (double) te * 100 / timer;
          ts = tts, te = tte;
        }
        ts += delay, te += delay;
        int f1 = 0, f2 = 0;
        if (ts < 0)
        {
          f1 = 1, ts *= (-1);
        }
        if (te < 0)
        {
          f2 = 1, te *= (-1);
        }
        long long sh = ts / 360000, sm = (ts % 360000) / 6000, ss = ((ts % 360000) % 6000) / 100, shs = ((ts % 360000) % 6000) % 100;
        long long eh = te / 360000, em = (te % 360000) / 6000, es = ((te % 360000) % 6000) / 100, ehs = ((te % 360000) % 6000) % 100;
        for (long long i = 0; i < pps; ++i)
          printf("%c", s[i]);
        if (f1)
          printf("-");
        printf("%lld:%02lld:%02lld.%02lld", sh, sm, ss, shs);
        for (long long i = pps + 10 + fl1; i < ppe; ++i)
          printf("%c", s[i]);
        if(f2)
          printf("-");
        printf("%lld:%02lld:%02lld.%02lld", eh, em, es, ehs);
        for (long long i = ppe + 10 + fl2; i < strlen(s); ++i)
          printf("%c", s[i]);
        fgets(s, 102, stdin);
      }
      else if (!(s[ps] >= '0' && s[ps] <= '9') && !(s[pe] >= '0' && s[pe] <= '9'))
      {
        printf("%s", s);
        fgets(s, 1002, stdin);
      }
      else if (!(s[ps] >= '0' && s[ps] <= '9') && (s[pe] >= '0' && s[pe] <= '9'))
      {
        te += (s[pe] - '0') * 360000;
        pe += 2;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0')) * 6000;
        pe += 3;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0')) * 100;
        pe += 3;
        te += ((s[pe] - '0') * 10 + (s[pe + 1] - '0'));
        te *= m2;
        if (timer > -1)
        {
          double tte = (double) te * 100 / timer;
          te = tte;
        }
        te += delay;
        long long f2 = 0;
        if (te < 0)
        {
          f2 = 1, te *= (-1);
        }
        long long eh = te / 360000, em = (te % 360000) / 6000, es = ((te % 360000) % 6000) / 100, ehs = ((te % 360000) % 6000) % 100;
        for (long long i = 0; i < ppe; ++i)
          printf("%c", s[i]);
        if (f2)
          printf("-");
        printf("%lld:%02lld:%02lld.%02lld", eh, em, es, ehs);
        for (long long i = ppe + 10 + fl2; i < strlen(s); ++i)
          printf("%c", s[i]);
        fgets(s, 102, stdin);
      }
      else if (!(s[pe] >= '0' && s[pe] <= '9') && (s[ps] >= '0' && s[ps] <= '9'))
      {
        ts += (s[ps] - '0') * 360000;
        ps += 2;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0')) * 6000;
        ps += 3;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0')) * 100;
        ps += 3;
        ts += ((s[ps] - '0') * 10 + (s[ps + 1] - '0'));
        ts *= m2;
        if (timer > -1)
        {
          double tts = (double) ts * 100 / timer;
          ts = tts;
        }
        ts += delay;
        long long f1 = 0;
        if (ts < 0)
        {
          f1 = 1, ts *= (-1);
        }
        long long sh = ts / 360000, sm = (ts % 360000) / 6000, ss = ((ts % 360000) % 6000) / 100, shs = ((ts % 360000) % 6000) % 100;
        for (long long i = 0; i < pps; ++i)
          printf("%c", s[i]);
        if (f1)
          printf("-");
        printf("%lld:%02lld:%02lld.%02lld", sh, sm, ss, shs);
        for (long long i = pps + 10 + fl1; i < strlen(s); ++i)
          printf("%c", s[i]);
        fgets(s, 102, stdin);
      }
    }
    else{
      printf("%s", s);
      fgets(s, 1002, stdin);
    }
  }
  return 0;
}
