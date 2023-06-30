#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"
#include "lwipopts.h"
#include "cgi.h"


static const tCGI cgi_handlers[] = {
    {
        /* Html request for "/leds.cgi" will start cgi_handler_basic */
        "/hello.cgi", cgi_handler_basic
    }
};



/* cgi-handler triggered by a request for "/leds.cgi" */
const char *
cgi_handler_basic(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    /* We use this handler for one page request only: "/leds.cgi"
     * and it is at position 0 in the tCGI array (see above).
     * So iIndex should be 0.
     */
    printf("cgi_handler_basic called with index %d\n", iIndex);


    /* Our response to the "SUBMIT" is to simply send the same page again*/
    return "/cgi.html";
}


/* initialize the CGI handler */
void
cgi_init(void)
{
    http_set_cgi_handlers(cgi_handlers, 1);
}



