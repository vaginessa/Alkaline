This component was taken from C# malware and steals passwords 'saved' by Internet Explorer.  The technique is very simple and only requires registry read access to run successfully.

The C# malware sample (along with source code) was provided by Lincoln Labs.  The original source contained a bug in the crypto setup that was fixed by UMBRAGE.  Below is the source code with comments added by UMBRAGE to aid in understanding the technique, which should make it easy to port to other langauges.
