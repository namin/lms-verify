// adapted from https://github.com/nodejs/http-parser/blob/master/bench.c

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

static const char original_data[] =
  "HTTP/1.1 301 Moved Permanently\r\n"
  "Location: http://www.google.com/\r\n"
  "Content-Type: text/html; charset=UTF-8\r\n"
  "Date: Sun, 26 Apr 2009 11:11:49 GMT\r\n"
  "Expires: Tue, 26 May 2009 11:11:49 GMT\r\n"
  "X-$PrototypeBI-Version: 1.6.0.3\r\n" /* $ char in header field */
  "Cache-Control: public, max-age=2592000\r\n"
  "Server: gws\r\n"
  "Content-Length:  219  \r\n"
  "\r\n"
  "<HTML><HEAD><meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\">\n"
  "<TITLE>301 Moved</TITLE></HEAD><BODY>\n"
  "<H1>301 Moved</H1>\n"
  "The document has moved\n"
  "<A HREF=\"http://www.google.com/\">here</A>.\r\n"
  "</BODY></HTML>\r\n";

// TODO: don't miss the \r's
// TODO: allow more chars in header name field, all but ':' and spaces?
// TODO: should we be more relaxed about Content-Length?
static char data[] =
  "HTTP/1.1 301 Moved Permanently\n"
  "Location: http://www.google.com/\n"
  "Content-Type: text/html; charset=UTF-8\n"
  "Date: Sun, 26 Apr 2009 11:11:49 GMT\n"
  "Expires: Tue, 26 May 2009 11:11:49 GMT\n"
  //"X-$PrototypeBI-Version: 1.6.0.3\n" /* $ char in header field */
  "Cache-Control: public, max-age=2592000\n"
  "Server: gws\n"
  "Content-Length:  216  \n"
  "\n"
  "<HTML><HEAD><meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\">\n" // 79
  "<TITLE>301 Moved</TITLE></HEAD><BODY>\n" // 38
  "<H1>301 Moved</H1>\n" // 18
  "The document has moved\n" // 23
  "<A HREF=\"http://www.google.com/\">here</A>.\n" // 43
  "</BODY></HTML>\n"; // 15-1

static const size_t data_len = 216;

int bench(int iter_count, int silent) {
  int i;
  int err;
  struct timeval start;
  struct timeval end;
  float rps;
  size_t data_size = sizeof(data)-1;
  int noise_index = data_size-20;
  char noise_val = '0';

  if (!silent) {
    err = gettimeofday(&start, NULL);
    assert(err == 0);
  }

  for (i = 0; i < iter_count; i++) {
    size_t parsed;

    data[noise_index] = noise_val; // force computation in the loop

    parsed = p(data);
    assert(parsed == data_len);
  }

  if (!silent) {
    err = gettimeofday(&end, NULL);
    assert(err == 0);

    fprintf(stdout, "Benchmark result:\n");

    rps = (float) (end.tv_sec - start.tv_sec) +
          (end.tv_usec - start.tv_usec) * 1e-6f;
    fprintf(stdout, "Took %f seconds to run\n", rps);

    rps = (float) iter_count / rps;
    fprintf(stdout, "%f req/sec\n", rps);
    fflush(stdout);
  }

  return 0;
}

int main(int argc, char** argv) {
  if (argc == 2 && strcmp(argv[1], "infinite") == 0) {
    for (;;)
      bench(5000000, 1);
    return 0;
  } else {
    return bench(5000000, 0);
  }
}
