
//2 diff. versions of MessageBox notify


VOID XNotifyUI(PWCHAR pwszStringParam)
{
 if (KeGetCurrentProcessType() != PROC_USER)
 {
  HANDLE th = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)XNotifyDoQueueUI, (LPVOID)pwszStringParam, CREATE_SUSPENDED, NULL);
  if (th == NULL) return;
  ResumeThread(th);
 }
 else
  XNotifyDoQueueUI(pwszStringParam); 
}


//==============================================




LPCWSTR Buttons[1] = { L"OK" };
		while (XShowMessageBoxUI(XUSER_INDEX_ANY, title, msg1, 1, Buttons, 0, XMB_ALERTICON, &g_mb_result, &g_xol) == ERROR_ACCESS_DENIED) Sleep(500);
		while (!XHasOverlappedIoCompleted(&g_xol)) Sleep(500);
