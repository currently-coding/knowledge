/******/ (() => { // webpackBootstrap
/******/ 	var __webpack_modules__ = ({

/***/ 526:
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.watchAndAddCopyButtonsToDOM = watchAndAddCopyButtonsToDOM;
const addCopyButtonToCallout_1 = __webpack_require__(769);
function watchAndAddCopyButtonsToDOM({ pluginSettingsManager, }) {
    const observer = watchDOMForNewCallouts(pluginSettingsManager);
    addAllCopyButtons(pluginSettingsManager);
    return observer;
}
function watchDOMForNewCallouts(pluginSettingsManager) {
    const observer = getCalloutDivObserver(pluginSettingsManager);
    observer.observe(document.body, { childList: true, subtree: true });
    return observer;
}
function getCalloutDivObserver(pluginSettingsManager) {
    return new MutationObserver((mutations) => {
        mutations.forEach((mutation) => {
            mutation.addedNodes.forEach((node) => {
                if (!(node instanceof HTMLElement)) {
                    return;
                }
                const newCMCalloutNodes = node.querySelectorAll(".cm-callout");
                for (const calloutNode of newCMCalloutNodes) {
                    addCopyPlainTextButtonAndMoveEditBlockButton({
                        calloutNode,
                        isCMCalloutNode: true,
                        pluginSettingsManager,
                    });
                }
                const newCalloutNodes = node.querySelectorAll(".callout");
                for (const calloutNode of newCalloutNodes) {
                    addCopyPlainTextButtonAndMoveEditBlockButton({
                        calloutNode,
                        isCMCalloutNode: false,
                        pluginSettingsManager,
                    });
                }
            });
        });
    });
}
function addAllCopyButtons(pluginSettingsManager) {
    const cmCalloutNodes = document.querySelectorAll(".cm-callout");
    cmCalloutNodes.forEach((calloutNode) => addCopyPlainTextButtonAndMoveEditBlockButton({
        calloutNode,
        isCMCalloutNode: true,
        pluginSettingsManager,
    }));
    const calloutNodes = document.querySelectorAll(".callout");
    calloutNodes.forEach((calloutNode) => addCopyPlainTextButtonAndMoveEditBlockButton({
        calloutNode,
        isCMCalloutNode: false,
        pluginSettingsManager,
    }));
}
function addCopyPlainTextButtonAndMoveEditBlockButton({ calloutNode, isCMCalloutNode, pluginSettingsManager, }) {
    (0, addCopyButtonToCallout_1.addCopyPlainTextButtonToCalloutDiv)({ calloutNode, isCMCalloutNode, pluginSettingsManager });
    (0, addCopyButtonToCallout_1.moveEditBlockButtonToCalloutActionButtonsWrapper)(calloutNode);
}


/***/ }),

/***/ 223:
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {

"use strict";

var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.createCopyButton = createCopyButton;
const classnames_1 = __importDefault(__webpack_require__(942));
const obsidian_1 = __webpack_require__(795);
const addClassNames_1 = __webpack_require__(661);
function createCopyButton({ getCalloutBodyText, tooltipText, className, }) {
    const copyButton = document.createElement("div");
    (0, addClassNames_1.addClassNames)({ el: copyButton, classNames: (0, classnames_1.default)("callout-copy-button", className) });
    copyButton.setAttribute("aria-label", tooltipText);
    (0, obsidian_1.setIcon)(copyButton, "copy");
    // Using `mousedown` lets us prevent the default behavior of the `click` event (e.g. taking focus
    // which changes cursor/selection position in the editor)
    copyButton.addEventListener("mousedown", (e) => {
        e.preventDefault();
        if (copyButton.hasAttribute("disabled"))
            return;
        void onCopyButtonClick({ getCalloutBodyText, copyButton });
    });
    // For some reason still need this to prevent the default behavior of clicking the callout block
    // (i.e. moving the cursor into the block to edit the callout)
    copyButton.addEventListener("click", (e) => {
        e.stopPropagation();
    });
    return copyButton;
}
async function onCopyButtonClick({ getCalloutBodyText, copyButton, }) {
    if (copyButton.hasAttribute("disabled"))
        return;
    const calloutBodyText = getCalloutBodyText();
    if (calloutBodyText === null) {
        new obsidian_1.Notice("Error: Could not copy callout text");
        return;
    }
    await navigator.clipboard.writeText(calloutBodyText);
    // console.log(`Copied: ${JSON.stringify(calloutBodyText)}`);
    (0, obsidian_1.setIcon)(copyButton, "check");
    copyButton.classList.add("just-copied");
    copyButton.setAttribute("disabled", "true");
    setTimeout(() => {
        (0, obsidian_1.setIcon)(copyButton, "copy");
        copyButton.classList.remove("just-copied");
        copyButton.removeAttribute("disabled");
    }, 3000);
}


/***/ }),

/***/ 105:
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.getMarkdownPostProcessor = getMarkdownPostProcessor;
const addCopyButtonToCallout_1 = __webpack_require__(769);
const getCalloutBodyText_1 = __webpack_require__(899);
function getMarkdownPostProcessor({ pluginSettingsManager, }) {
    return (el, ctx) => {
        postProcessMarkdown(el, ctx, pluginSettingsManager);
    };
}
function postProcessMarkdown(el, ctx, pluginSettingsManager) {
    const { topLevelCallout, isCMCalloutNode } = getTopLevelCalloutNode(el);
    if (topLevelCallout === null) {
        // Callout node not found within the rendered markdown section
        return;
    }
    maybeAddCopyMarkdownFromSectionInfoButtonToCallout({
        calloutNode: topLevelCallout,
        ctx,
        isCMCalloutNode,
        pluginSettingsManager,
    });
    (0, addCopyButtonToCallout_1.addCopyPlainTextButtonToCalloutDiv)({
        calloutNode: topLevelCallout,
        isCMCalloutNode,
        pluginSettingsManager,
    });
    const nestedCallouts = topLevelCallout.findAll(".callout");
    nestedCallouts.forEach((nestedCallout) => {
        (0, addCopyButtonToCallout_1.addCopyPlainTextButtonToCalloutDiv)({
            calloutNode: nestedCallout,
            isCMCalloutNode: false,
            pluginSettingsManager,
        });
    });
}
function getTopLevelCalloutNode(el) {
    const maybeCMCalloutNode = el.closest(".cm-callout");
    if (maybeCMCalloutNode !== null) {
        return { topLevelCallout: maybeCMCalloutNode, isCMCalloutNode: true };
    }
    const maybeTopLevelCallout = el.querySelector(".callout");
    if (maybeTopLevelCallout === null) {
        return { topLevelCallout: null, isCMCalloutNode: false };
    }
    return { topLevelCallout: maybeTopLevelCallout, isCMCalloutNode: false };
}
function maybeAddCopyMarkdownFromSectionInfoButtonToCallout({ calloutNode, ctx, isCMCalloutNode, pluginSettingsManager, }) {
    if (isCMCalloutNode) {
        // Section info not available in Live Preview mode; not adding copy markdown button
        return;
    }
    if (calloutNode.querySelector(".callout-copy-button-markdown")) {
        // Copy Markdown button already exists; not adding another one
        return;
    }
    (0, addCopyButtonToCallout_1.addCopyButtonToCallout)({
        calloutNode,
        getCalloutBodyText: () => {
            const calloutSectionInfo = ctx.getSectionInfo(calloutNode);
            if (calloutSectionInfo === null) {
                // Section info not available for some reason
                return null;
            }
            const calloutBodyText = (0, getCalloutBodyText_1.getCalloutBodyTextFromSectionInfo)(calloutSectionInfo);
            if (calloutBodyText === null) {
                return null;
            }
            return calloutBodyText;
        },
        tooltipText: "Copy (Markdown)",
        buttonClassName: "callout-copy-button-markdown",
        isCMCalloutNode,
        pluginSettingsManager,
    });
}


/***/ }),

/***/ 451:
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {

"use strict";

var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.PluginSettingsManager = exports.DEFAULT_SETTINGS = void 0;
const classnames_1 = __importDefault(__webpack_require__(942));
const obsidian_1 = __webpack_require__(795);
/**
 * Deep-clones the given settings. There's currently only one nested object: `autoSelectionModes`.
 */
function deepCloneSettings(settings) {
    const clone = { ...settings };
    clone.sourceModeSettings = { ...settings.sourceModeSettings };
    clone.readingModeSettings = { ...settings.readingModeSettings };
    return clone;
}
exports.DEFAULT_SETTINGS = {
    pluginVersion: "1.0.0",
    showCopyFormatIndicators: false,
    sourceModeSettings: {
        showCopyButtonOnlyOnLineHover: false,
    },
    readingModeSettings: {
        showCopyMarkdownButton: true,
        showCopyPlainTextButton: true,
    },
};
class PluginSettingsManager extends obsidian_1.PluginSettingTab {
    constructor(plugin) {
        super(plugin.app, plugin);
        this.plugin = plugin;
        this.settings = deepCloneSettings(exports.DEFAULT_SETTINGS);
    }
    async setupSettingsTab() {
        this.settings = await this.loadSettings();
        this.addSettingTab();
    }
    /**
     * Returns the class names for the copy buttons based on the plugin settings.
     */
    getCopyButtonSettingsClassName() {
        return (0, classnames_1.default)(this.getCopyButtonSettingsClassNames());
    }
    async loadSettings() {
        const loadedSettings = (await this.plugin.loadData());
        if (loadedSettings !== null) {
            return loadedSettings;
        }
        return await this.initializeSettings();
    }
    async initializeSettings() {
        const settings = deepCloneSettings(exports.DEFAULT_SETTINGS);
        await this.plugin.saveData(settings);
        return settings;
    }
    addSettingTab() {
        this.plugin.addSettingTab(this);
    }
    getSetting(settingKey) {
        return this.settings[settingKey];
    }
    async setSetting(settingKey, value) {
        this.settings[settingKey] = value;
        await this.saveSettings();
        this.refreshCalloutCopyButtonClassNames();
    }
    refreshCalloutCopyButtonClassNames() {
        const newClassNames = this.getCopyButtonSettingsClassNames();
        const copyButtons = document.querySelectorAll(".callout-copy-button");
        for (const copyButton of copyButtons) {
            for (const [className, shouldAdd] of Object.entries(newClassNames)) {
                if (shouldAdd) {
                    copyButton.addClass(className);
                }
                else {
                    copyButton.removeClass(className);
                }
            }
        }
    }
    getCopyButtonSettingsClassNames() {
        const showCopyFormatIndicators = this.getSetting("showCopyFormatIndicators");
        const { showCopyButtonOnlyOnLineHover } = this.getSetting("sourceModeSettings");
        const { showCopyMarkdownButton: showCopyMarkdownButton, showCopyPlainTextButton: showCopyPlainTextButton, } = this.getSetting("readingModeSettings");
        return {
            "show-copy-format-indicators": showCopyFormatIndicators,
            "show-source-mode-copy-button-only-on-line-hover": showCopyButtonOnlyOnLineHover,
            "show-reading-mode-copy-markdown-buttons": showCopyMarkdownButton,
            "show-reading-mode-copy-plain-text-buttons": showCopyPlainTextButton,
        };
    }
    async setSourceModeSetting(modeKey, value) {
        const newSourceModeSettings = { ...this.settings.sourceModeSettings, [modeKey]: value };
        await this.setSetting("sourceModeSettings", newSourceModeSettings);
    }
    async setReadingModeSetting(modeKey, value) {
        const newReadingModeSettings = { ...this.settings.readingModeSettings, [modeKey]: value };
        await this.setSetting("readingModeSettings", newReadingModeSettings);
    }
    display() {
        const { containerEl } = this;
        containerEl.empty();
        this.displayButtonAppearanceSettings();
        this.displaySourceModeSettings();
        this.displayReadingModeSettings();
    }
    displayButtonAppearanceSettings() {
        new obsidian_1.Setting(this.containerEl).setName("Appearance").setHeading();
        this.displayCopyFormatIndicatorsSetting();
    }
    displayCopyFormatIndicatorsSetting() {
        new obsidian_1.Setting(this.containerEl)
            .setName("Show copy format indicators on copy buttons")
            .setDesc("Whether to add little 'P' (plain text) and 'M' (Markdown) indicators to the copy buttons that indicate what format the copied content will be in.")
            .addToggle((toggle) => toggle
            .setValue(this.settings.showCopyFormatIndicators)
            .onChange((value) => this.setSetting("showCopyFormatIndicators", value)));
    }
    displaySourceModeSettings() {
        new obsidian_1.Setting(this.containerEl).setName("Source mode").setHeading();
        this.displayShowCopyButtonOnlyOnLineHoverSetting();
    }
    displayShowCopyButtonOnlyOnLineHoverSetting() {
        new obsidian_1.Setting(this.containerEl)
            .setName("Show copy button only on line hover")
            .setDesc("If disabled, the copy buttons in Source Mode will always be visible.")
            .addToggle((toggle) => toggle
            .setValue(this.settings.sourceModeSettings.showCopyButtonOnlyOnLineHover)
            .onChange((value) => this.setSourceModeSetting("showCopyButtonOnlyOnLineHover", value)));
    }
    displayReadingModeSettings() {
        new obsidian_1.Setting(this.containerEl).setName("Reading mode").setHeading();
        this.displayShowCopyMarkdownButtonSetting();
        this.displayShowCopyPlainTextButtonSetting();
    }
    displayShowCopyMarkdownButtonSetting() {
        new obsidian_1.Setting(this.containerEl)
            .setName("Show 'Copy (Markdown)' button")
            .setDesc("Whether to add 'Copy (Markdown)' buttons to callout blocks in Reading Mode.")
            .addToggle((toggle) => toggle
            .setValue(this.settings.readingModeSettings.showCopyMarkdownButton)
            .onChange((value) => this.setReadingModeSetting("showCopyMarkdownButton", value)));
    }
    displayShowCopyPlainTextButtonSetting() {
        new obsidian_1.Setting(this.containerEl)
            .setName("Show 'Copy (plain text)' button")
            .setDesc("Whether to add 'Copy (plain text)' buttons to callout blocks in Reading Mode.")
            .addToggle((toggle) => toggle
            .setValue(this.settings.readingModeSettings.showCopyPlainTextButton)
            .onChange((value) => this.setReadingModeSetting("showCopyPlainTextButton", value)));
    }
    async saveSettings() {
        await this.plugin.saveData(this.settings);
    }
}
exports.PluginSettingsManager = PluginSettingsManager;


/***/ }),

/***/ 661:
/***/ ((__unused_webpack_module, exports) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.addClassNames = addClassNames;
/**
 * Add multiple class names to an element given a string of space-separated class names.
 */
function addClassNames({ el, classNames }) {
    el.addClasses(classNames.split(" "));
}


/***/ }),

/***/ 769:
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {

"use strict";

var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.addCopyPlainTextButtonToCalloutDiv = addCopyPlainTextButtonToCalloutDiv;
exports.addCopyButtonToCallout = addCopyButtonToCallout;
exports.moveEditBlockButtonToCalloutActionButtonsWrapper = moveEditBlockButtonToCalloutActionButtonsWrapper;
const classnames_1 = __importDefault(__webpack_require__(942));
const copyButton_1 = __webpack_require__(223);
const getCalloutBodyText_1 = __webpack_require__(899);
function addCopyPlainTextButtonToCalloutDiv({ calloutNode, isCMCalloutNode, pluginSettingsManager, }) {
    if (calloutNode.querySelector(".callout-copy-button-plain-text") !== null) {
        // Copy button already exists; not adding another one
        return;
    }
    addCopyButtonToCallout({
        calloutNode,
        getCalloutBodyText: () => (0, getCalloutBodyText_1.getCalloutBodyTextFromInnerText)(calloutNode),
        tooltipText: "Copy (plain text)",
        buttonClassName: "callout-copy-button-plain-text",
        isCMCalloutNode,
        pluginSettingsManager,
    });
}
function addCopyButtonToCallout({ calloutNode, getCalloutBodyText, tooltipText, buttonClassName, isCMCalloutNode, pluginSettingsManager, }) {
    const settingsClassName = pluginSettingsManager.getCopyButtonSettingsClassName();
    const copyButton = (0, copyButton_1.createCopyButton)({
        getCalloutBodyText,
        className: (0, classnames_1.default)("callout-copy-button", buttonClassName, settingsClassName),
        tooltipText,
    });
    const actionButtonsWrapper = getOrCreateCalloutActionButtonsWrapper({
        calloutNode,
        isCMCalloutNode,
    });
    actionButtonsWrapper.appendChild(copyButton);
}
function moveEditBlockButtonToCalloutActionButtonsWrapper(calloutNode) {
    const closestCMCallout = calloutNode.closest(".cm-callout");
    if (closestCMCallout === null) {
        // CM callout not found; not moving edit block button
        return;
    }
    const editBlockButton = closestCMCallout.querySelector(".edit-block-button");
    if (editBlockButton === null) {
        // Edit block button not found; not moving it
        return;
    }
    const actionButtonsWrapper = getOrCreateCalloutActionButtonsWrapper({
        calloutNode: closestCMCallout,
        isCMCalloutNode: true,
    });
    if (actionButtonsWrapper.contains(editBlockButton)) {
        // Edit block button already in action buttons wrapper; not moving it
        return;
    }
    actionButtonsWrapper.appendChild(editBlockButton);
}
function getOrCreateCalloutActionButtonsWrapper({ calloutNode, isCMCalloutNode, }) {
    const existingCalloutActionButtonsWrapper = getCalloutActionButtonsWrapper({
        calloutNode,
        isCMCalloutNode,
    });
    if (existingCalloutActionButtonsWrapper !== null) {
        // Action buttons wrapper already exists
        return existingCalloutActionButtonsWrapper;
    }
    return addCalloutActionButtonsWrapperToCalloutNode({ calloutNode, isCMCalloutNode });
}
function getCalloutActionButtonsWrapper({ calloutNode, isCMCalloutNode, }) {
    if (!isCMCalloutNode) {
        return getFirstDirectChildWithClass(calloutNode, "callout-action-buttons");
    }
    const calloutDiv = calloutNode.querySelector(".callout");
    if (calloutDiv === null) {
        return null;
    }
    return getFirstDirectChildWithClass(calloutDiv, "callout-action-buttons");
}
function getFirstDirectChildWithClass(parent, className) {
    for (const child of parent.children) {
        if (child instanceof HTMLElement && child.classList.contains(className)) {
            return child;
        }
    }
    return null;
}
function addCalloutActionButtonsWrapperToCalloutNode({ calloutNode, isCMCalloutNode, }) {
    const calloutActionButtonsWrapper = document.createElement("div");
    calloutActionButtonsWrapper.classList.add("callout-action-buttons");
    if (!isCMCalloutNode) {
        // Not a CM callout; adding action buttons wrapper to callout
        calloutNode.appendChild(calloutActionButtonsWrapper);
        return calloutActionButtonsWrapper;
    }
    const calloutDiv = calloutNode.querySelector(".callout");
    if (calloutDiv === null) {
        // Callout div not found; not adding action buttons wrapper
        return calloutActionButtonsWrapper;
    }
    calloutDiv.appendChild(calloutActionButtonsWrapper);
    return calloutActionButtonsWrapper;
}


/***/ }),

/***/ 776:
/***/ ((__unused_webpack_module, exports) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.removeCopyButtonsAndRestoreEditBlockButton = removeCopyButtonsAndRestoreEditBlockButton;
/**
 * Removes the copy buttons and actions wrappers added by this plugin, and restores the edit block
 * button to its original position as a direct child of the `.cm-callout` element.
 */
function removeCopyButtonsAndRestoreEditBlockButton() {
    document.querySelectorAll(".callout-action-buttons").forEach((wrapper) => {
        const editBlockButton = wrapper.querySelector(".edit-block-button");
        moveEditBlockButtonOutOfWrapper(editBlockButton);
        wrapper.remove();
    });
    document.querySelectorAll(".callout-copy-button").forEach((button) => {
        button.remove();
    });
}
function moveEditBlockButtonOutOfWrapper(editBlockButton) {
    if (editBlockButton === null) {
        return;
    }
    const cmCalloutParent = editBlockButton.closest(".cm-callout");
    if (cmCalloutParent === null) {
        return;
    }
    cmCalloutParent.appendChild(editBlockButton);
}


/***/ }),

/***/ 899:
/***/ ((__unused_webpack_module, exports) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.getCalloutBodyTextFromInnerText = getCalloutBodyTextFromInnerText;
exports.getCalloutBodyLines = getCalloutBodyLines;
exports.getCalloutBodyTextFromSectionInfo = getCalloutBodyTextFromSectionInfo;
const CALLOUT_HEADER_WITH_INDENT_CAPTURE_REGEX = /^((?:> )+)\[!.+\]/;
function getCalloutBodyTextFromInnerText(calloutNode) {
    return calloutNode.innerText.split("\n").slice(1).join("\n").trim();
}
/**
 * Returns the lines of the callout body, starting from the line after the callout header, with the
 * callout indent (matched from the callout header) stripped.
 */
function getCalloutBodyLines({ doc, calloutIndent, bodyStartLine, }) {
    const calloutBodyLines = [];
    for (let i = bodyStartLine; i <= doc.lines; i++) {
        const maybeBodyLineWithIndent = doc.line(i).text;
        if (!maybeBodyLineWithIndent.startsWith(calloutIndent)) {
            return calloutBodyLines;
        }
        const calloutBodyLineText = maybeBodyLineWithIndent.slice(calloutIndent.length);
        calloutBodyLines.push(calloutBodyLineText);
    }
    return calloutBodyLines;
}
function getCalloutBodyTextFromSectionInfo(calloutSectionInfo) {
    const calloutBodyLines = getCalloutBodyLinesFromSectionInfo(calloutSectionInfo);
    if (calloutBodyLines === null) {
        return null;
    }
    return calloutBodyLines.join("\n");
}
function getCalloutBodyLinesFromSectionInfo(calloutSectionInfo) {
    const { text, lineStart, lineEnd } = calloutSectionInfo;
    const allLines = text.split("\n");
    const headerLine = allLines[lineStart];
    if (headerLine === undefined) {
        // Line start is out of bounds
        return null;
    }
    const calloutIndent = CALLOUT_HEADER_WITH_INDENT_CAPTURE_REGEX.exec(headerLine)?.[1];
    if (calloutIndent === undefined) {
        // Line does not match callout header regex
        return null;
    }
    const calloutBodyLines = [];
    for (const maybeBodyLineWithIndent of allLines.slice(lineStart + 1, lineEnd + 1)) {
        if (!maybeBodyLineWithIndent.startsWith(calloutIndent)) {
            return calloutBodyLines;
        }
        const calloutBodyLineText = maybeBodyLineWithIndent.slice(calloutIndent.length);
        calloutBodyLines.push(calloutBodyLineText);
    }
    return calloutBodyLines;
}


/***/ }),

/***/ 170:
/***/ (function(__unused_webpack_module, exports, __webpack_require__) {

"use strict";

var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.CopyButtonWidget = void 0;
const view_1 = __webpack_require__(898);
const classnames_1 = __importDefault(__webpack_require__(942));
const obsidian_1 = __webpack_require__(795);
const addClassNames_1 = __webpack_require__(661);
class CopyButtonWidget extends view_1.WidgetType {
    constructor(text, pluginSettingsManager) {
        super();
        this.text = text;
        this.pluginSettingsManager = pluginSettingsManager;
    }
    toDOM() {
        const copyButton = document.createElement("div");
        const className = (0, classnames_1.default)("callout-copy-button", "callout-copy-button-widget", "callout-copy-button-markdown", this.pluginSettingsManager.getCopyButtonSettingsClassName());
        (0, addClassNames_1.addClassNames)({ el: copyButton, classNames: className });
        copyButton.setAttribute("aria-label", "Copy (Markdown)");
        (0, obsidian_1.setIcon)(copyButton, "copy");
        copyButton.addEventListener("click", (e) => {
            e.stopPropagation();
            if (copyButton.hasAttribute("disabled"))
                return;
            navigator.clipboard
                .writeText(this.text)
                .then(() => {
                // console.log(`Copied: ${JSON.stringify(this.text)}`);
                (0, obsidian_1.setIcon)(copyButton, "check");
                copyButton.addClass("just-copied");
                copyButton.setAttribute("disabled", "true");
                setTimeout(() => {
                    (0, obsidian_1.setIcon)(copyButton, "copy");
                    copyButton.removeClass("just-copied");
                    copyButton.removeAttribute("disabled");
                }, 3000);
            })
                .catch((error) => {
                console.error(error);
            });
        });
        return copyButton;
    }
    ignoreEvent() {
        // Prevent clicks from being interpreted as editor interactions
        return true;
    }
}
exports.CopyButtonWidget = CopyButtonWidget;


/***/ }),

/***/ 333:
/***/ ((__unused_webpack_module, exports, __webpack_require__) => {

"use strict";

Object.defineProperty(exports, "__esModule", ({ value: true }));
exports.createCalloutCopyButtonViewPlugin = createCalloutCopyButtonViewPlugin;
const state_1 = __webpack_require__(20);
const view_1 = __webpack_require__(898);
const getCalloutBodyText_1 = __webpack_require__(899);
const copyButtonWidget_1 = __webpack_require__(170);
const CALLOUT_HEADER_WITH_INDENT_CAPTURE_REGEX = /^((?:> )+)\[!.+\]/;
function createCalloutCopyButtonViewPlugin(pluginSettingsManager) {
    class CalloutCopyButtonViewPlugin {
        constructor(view) {
            this.decorations = this.buildDecorations(view);
        }
        update(update) {
            if (update.docChanged || update.viewportChanged) {
                this.decorations = this.buildDecorations(update.view);
            }
        }
        destroy() {
            /* no-op */
        }
        buildDecorations(view) {
            const builder = new state_1.RangeSetBuilder();
            const doc = view.state.doc;
            for (let line = 1; line <= doc.lines; line++) {
                const lineText = doc.line(line).text;
                const calloutIndent = CALLOUT_HEADER_WITH_INDENT_CAPTURE_REGEX.exec(lineText)?.[1];
                if (calloutIndent === undefined) {
                    // Not the start of a callout block
                    continue;
                }
                const calloutBodyLines = (0, getCalloutBodyText_1.getCalloutBodyLines)({
                    doc,
                    calloutIndent,
                    bodyStartLine: line + 1,
                });
                const calloutBodyText = calloutBodyLines.join("\n");
                const deco = view_1.Decoration.widget({
                    widget: new copyButtonWidget_1.CopyButtonWidget(calloutBodyText, pluginSettingsManager),
                    side: 1, // Place the widget on the right
                });
                const from = doc.line(line).from;
                builder.add(from, from, deco);
            }
            return builder.finish();
        }
    }
    const pluginSpec = {
        decorations: (value) => value.decorations,
    };
    return view_1.ViewPlugin.fromClass(CalloutCopyButtonViewPlugin, pluginSpec);
}


/***/ }),

/***/ 20:
/***/ ((module) => {

"use strict";
module.exports = require("@codemirror/state");

/***/ }),

/***/ 898:
/***/ ((module) => {

"use strict";
module.exports = require("@codemirror/view");

/***/ }),

/***/ 795:
/***/ ((module) => {

"use strict";
module.exports = require("obsidian");

/***/ }),

/***/ 942:
/***/ ((module, exports) => {

var __WEBPACK_AMD_DEFINE_ARRAY__, __WEBPACK_AMD_DEFINE_RESULT__;/*!
	Copyright (c) 2018 Jed Watson.
	Licensed under the MIT License (MIT), see
	http://jedwatson.github.io/classnames
*/
/* global define */

(function () {
	'use strict';

	var hasOwn = {}.hasOwnProperty;

	function classNames () {
		var classes = '';

		for (var i = 0; i < arguments.length; i++) {
			var arg = arguments[i];
			if (arg) {
				classes = appendClass(classes, parseValue(arg));
			}
		}

		return classes;
	}

	function parseValue (arg) {
		if (typeof arg === 'string' || typeof arg === 'number') {
			return arg;
		}

		if (typeof arg !== 'object') {
			return '';
		}

		if (Array.isArray(arg)) {
			return classNames.apply(null, arg);
		}

		if (arg.toString !== Object.prototype.toString && !arg.toString.toString().includes('[native code]')) {
			return arg.toString();
		}

		var classes = '';

		for (var key in arg) {
			if (hasOwn.call(arg, key) && arg[key]) {
				classes = appendClass(classes, key);
			}
		}

		return classes;
	}

	function appendClass (value, newClass) {
		if (!newClass) {
			return value;
		}
	
		if (value) {
			return value + ' ' + newClass;
		}
	
		return value + newClass;
	}

	if ( true && module.exports) {
		classNames.default = classNames;
		module.exports = classNames;
	} else if (true) {
		// register as 'classnames', consistent with npm package name
		!(__WEBPACK_AMD_DEFINE_ARRAY__ = [], __WEBPACK_AMD_DEFINE_RESULT__ = (function () {
			return classNames;
		}).apply(exports, __WEBPACK_AMD_DEFINE_ARRAY__),
		__WEBPACK_AMD_DEFINE_RESULT__ !== undefined && (module.exports = __WEBPACK_AMD_DEFINE_RESULT__));
	} else {}
}());


/***/ })

/******/ 	});
/************************************************************************/
/******/ 	// The module cache
/******/ 	var __webpack_module_cache__ = {};
/******/ 	
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/ 		// Check if module is in cache
/******/ 		var cachedModule = __webpack_module_cache__[moduleId];
/******/ 		if (cachedModule !== undefined) {
/******/ 			return cachedModule.exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = __webpack_module_cache__[moduleId] = {
/******/ 			// no module.id needed
/******/ 			// no module.loaded needed
/******/ 			exports: {}
/******/ 		};
/******/ 	
/******/ 		// Execute the module function
/******/ 		__webpack_modules__[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/ 	
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/ 	
/************************************************************************/
var __webpack_exports__ = {};
// This entry needs to be wrapped in an IIFE because it needs to be in strict mode.
(() => {
"use strict";
var exports = __webpack_exports__;

Object.defineProperty(exports, "__esModule", ({ value: true }));
const obsidian_1 = __webpack_require__(795);
const DOMObserver_1 = __webpack_require__(526);
const markdownPostProcessor_1 = __webpack_require__(105);
const settings_1 = __webpack_require__(451);
const cleanupDOM_1 = __webpack_require__(776);
const viewPlugin_1 = __webpack_require__(333);
class CalloutCopyButtonPlugin extends obsidian_1.Plugin {
    constructor() {
        super(...arguments);
        this.calloutDivObserver = null;
        this.pluginSettingsManager = new settings_1.PluginSettingsManager(this);
    }
    logInfo(message) {
        console.log(`${this.manifest.name}: ${message}`);
    }
    async onload() {
        this.logInfo("Loading Callout Copy Button plugin");
        const { pluginSettingsManager } = this;
        await pluginSettingsManager.setupSettingsTab();
        this.app.workspace.onLayoutReady(() => {
            const calloutCopyButtonViewPlugin = (0, viewPlugin_1.createCalloutCopyButtonViewPlugin)(pluginSettingsManager);
            this.registerEditorExtension([calloutCopyButtonViewPlugin]);
            this.registerMarkdownPostProcessor((0, markdownPostProcessor_1.getMarkdownPostProcessor)({ pluginSettingsManager }));
            this.calloutDivObserver = (0, DOMObserver_1.watchAndAddCopyButtonsToDOM)({ pluginSettingsManager });
        });
    }
    onunload() {
        this.logInfo("Unloading Callout Copy Button plugin");
        (0, cleanupDOM_1.removeCopyButtonsAndRestoreEditBlockButton)();
        this.disconnectCalloutDivObserver();
    }
    disconnectCalloutDivObserver() {
        if (this.calloutDivObserver === null) {
            return;
        }
        this.calloutDivObserver.disconnect();
        this.calloutDivObserver = null;
    }
}
exports["default"] = CalloutCopyButtonPlugin;

})();

var __webpack_export_target__ = exports;
for(var __webpack_i__ in __webpack_exports__) __webpack_export_target__[__webpack_i__] = __webpack_exports__[__webpack_i__];
if(__webpack_exports__.__esModule) Object.defineProperty(__webpack_export_target__, "__esModule", { value: true });
/******/ })()
;
/* nosourcemap */