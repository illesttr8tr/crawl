#ifdef USE_TILE_LOCAL
#pragma once

#include "tilereg-text.h"

class CRTMenuEntry;
class PrecisionMenu;

/**
 * Expanded CRTRegion to support highlightable and clickable entries - felirx
 * The user of this region will have total control over the positioning of
 * objects at all times
 * The base class behaves like the current CRTRegion used commonly
 * It's identity is mapped to the CRT_NOMOUSESELECT value in TilesFramework
 *
 * Menu Entries are handled via pointers and are shared with whatever MenuClass
 * is using them. This is done to keep the keyboard selections in sync with mouse
 */
class CRTRegion : public TextRegion
{
public:

    CRTRegion(FontWrapper *font);
    virtual ~CRTRegion();

    virtual void render() override;
    virtual void clear() override;

    virtual int handle_mouse(MouseEvent& event) override;

    virtual void on_resize() override;

    void attach_menu(PrecisionMenu* menu);
    void detach_menu();
protected:
    PrecisionMenu* m_attached_menu;
};

/**
 * Enhanced Mouse handling for CRTRegion
 * The behaviour is CRT_SINGESELECT
 */
class CRTSingleSelect : public CRTRegion
{
public:
    CRTSingleSelect(FontWrapper* font);

    virtual int handle_mouse(MouseEvent& event) override;
};

#endif
