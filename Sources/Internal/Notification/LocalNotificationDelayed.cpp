#include "Notification/LocalNotificationDelayed.h"

namespace DAVA
{
void LocalNotificationDelayed::ImplShow()
{
    impl->PostDelayedNotification(title, text, delaySeconds, useSound);
}

void LocalNotificationDelayed::RemoveAllDelayedNotifications()
{
    impl->RemoveAllDelayedNotifications();
}

void LocalNotificationDelayed::Post()
{
    impl->PostDelayedNotification(title, text, delaySeconds, useSound);
}
}
