﻿#pragma once

//
// The following XML snippet needs to be added to Package.appxmanifest:
//
//<Extensions>
//  <Extension Category = "windows.activatableClass.inProcessServer">
//    <InProcessServer>
//      <Path>VideoEffects.WindowsPhone.dll</Path>
//      <ActivatableClass ActivatableClassId = "VideoEffects.ShaderEffectNv12" ThreadingModel = "both" />
//    </InProcessServer>
//  </Extension>
//</Extensions>
//

class ShaderEffectNv12 WrlSealed : public ShaderEffect
{
    InspectableClass(L"VideoEffects.ShaderEffectNv12", TrustLevel::BaseTrust);

public:

    virtual std::vector<unsigned long> GetSupportedFormats() const override;

private:

    void _Draw(
        long long time,
        const Microsoft::WRL::ComPtr<IMFDXGIBuffer>& inputBufferDxgi,
        const Microsoft::WRL::ComPtr<IMFDXGIBuffer>& outputBufferDxgi
        ) override;

};

ActivatableClass(ShaderEffectNv12);