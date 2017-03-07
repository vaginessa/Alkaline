The following techniques are user-land Windows API methods of logging keystrokes:

###### GetRawInputData API
Regsiter a device to receive raw input including keyboard events. (not yet evaluated)

###### GetKeyboardState/GetAsyncKeyboardState API
Another user-space technique that does not involve using hooks is to continuously make calls to GetKeyboardState(). The problem with this approach is the high CPU utilization that will be incurred by spinning in this loop. It may be possible to use this method in a more targeted fashion, for example, only when a particular windows has the focus (e.g. password entry).

Another potential issue with this approach is that there are a couple "caches" of key state data (Kaspersky's SecureList blog has a nifty post which discusses this), an asynchronous one, shared by all threads and a per-thread thread one that is updated to reflect reality whenever Windows feels like updating it.  This makes it complicated if, say, one is trying to get key(board) data when a different thread, which is likely in another process, is updating said data. 
