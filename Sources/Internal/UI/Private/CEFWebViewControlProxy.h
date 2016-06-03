#pragma once

#if defined(ENABLE_CEF_WEBVIEW)

#include <cef/include/internal/cef_ptr.h>
#include "UI/IWebViewControl.h"
#include "UI/Private/CEFController.h"

namespace DAVA
{
class WebViewControl : public IWebViewControl
{
public:
    WebViewControl(UIWebView& uiWebView);
    ~WebViewControl() override;

    // Initialize the control.
    void Initialize(const Rect& rect) override;

    // Open the URL requested.
    void OpenURL(const String& url) override;

    // Load html page from string
    void LoadHtmlString(const WideString& htmlString) override;
    void OpenFromBuffer(const String& htmlString, const FilePath& basePath) override;

    // Execute javascript string in webview
    void ExecuteJScript(const String& scriptString) override;

    // Delete all cookies associated with target URL
    void DeleteCookies(const String& url) override;
    // Get cookie for specific domain and name
    String GetCookie(const String& url, const String& name) const override;
    // Get the list of cookies for specific domain
    Map<String, String> GetCookies(const String& url) const override;

    // Size/pos/visibility changes.
    void SetRect(const Rect& rect) override;
    void SetVisible(bool isVisible, bool hierarchic) override;
    void SetBackgroundTransparency(bool enabled) override;
    UIControlBackground* GetContentBackground() override;

    void SetDelegate(IUIWebViewDelegate* webViewDelegate, UIWebView* webView) override;
    void SetRenderToTexture(bool value) override;
    bool IsRenderToTexture() const override;
    void Input(UIEvent* currentInput) override;
    void Update() override;

private:
    CefRefPtr<class CEFWebViewControl> impl;
    CEFController cefController;
};

} // namespace DAVA

#endif // ENABLE_CEF_WEBVIEW
