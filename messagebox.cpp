
//MessageBox notify for Xero updates


ID XNotifyUI(PWCHAR pwszStringParam)
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

LPCWSTR Buttons[1] = { L"Update Xero Bypass" }; // Button to redirect to live serv. update
		while (XShowMessageBoxUI(XUSER_INDEX_ANY, title, msg1, 1, Buttons, 0, XMB_ALERTICON, &g_mb_result, &g_xol) == ERROR_ACCESS_DENIED) Sleep(500);
		while (!XHasOverlappedIoCompleted(&g_xol)) Sleep(500);
			
		}
