#pragma once

#include "ActiveWeaponIcon/PlayerActiveWeaponIconPanel.h"
#include "BombIcon/PlayerBombIconPanel.h"

template <typename HookContext>
class PlayerWeaponIconPanelContext {
public:
    PlayerWeaponIconPanelContext(HookContext& hookContext, cs2::CUIPanel* panel) noexcept
        : _hookContext{hookContext}
        , _panel{panel}
    {
    }

    [[nodiscard]] decltype(auto) activeWeaponIconPanel() const noexcept
    {
        return _hookContext.template make<PlayerActiveWeaponIconPanel<HookContext>>(panel().children()[0]);
    }

    [[nodiscard]] decltype(auto) bombIconPanel() const noexcept
    {
        return _hookContext.template make<PlayerBombIconPanel<HookContext>>(panel().children()[1]);
    }

private:
    [[nodiscard]] decltype(auto) panel() const noexcept
    {
        return _hookContext.template make<PanoramaUiPanel>(_panel);
    }

    HookContext& _hookContext;
    cs2::CUIPanel* _panel;
};
