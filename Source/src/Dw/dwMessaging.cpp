void __cdecl dwUpdateMessaging(int controllerIndex) {
	const bdReference<bdCommonAddr> *v1; // eax
	bdReference<bdCommonAddr> v2; // [esp+1Ch] [ebp-Ch]
	TaskRecord *task; // [esp+20h] [ebp-8h]
	bdMessaging *messaging; // [esp+24h] [ebp-4h]

	ASSERT(Sys_IsMainThread() || Sys_IsServerThread());

	messaging = dwGetMessaging(controllerIndex);

	if (s_notificationsPending && messaging && !TaskManager2_TaskIsInProgress(task_processNotifications)) {
		task = TaskManager2_CreateTask(task_processNotifications, controllerIndex, 0, 0);

		ASSERT(task);

		s_notificationsPending = 0;
		v1 = (const bdReference<bdCommonAddr> *)bdMessaging::getNotifications((int)&v2, &s_notifications, 0, 10u, '\x01');
		// This is just setting a value, but because IDA doesn't recognize that, it calls the function instead.
		bdReference<bdCommonAddr>::operator=((bdReference<bdCommonAddr> *)&task->remoteTask, v1);
		bdReference<bdRemoteTask>::~bdReference<bdRemoteTask>(&v2);
		TaskManager2_StartTask(task);
	}
}
