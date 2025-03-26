"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
const obsidian_1 = require("obsidian");
class MarkdownFileTracker extends obsidian_1.Plugin {
    onload() {
        return __awaiter(this, void 0, void 0, function* () {
            console.log("Markdown File Tracker Loaded");
            yield this.trackMarkdownFiles();
        });
    }
    trackMarkdownFiles() {
        return __awaiter(this, void 0, void 0, function* () {
            const fileCounts = {};
            const files = this.app.vault.getFiles().filter(f => f.extension === "md");
            for (const file of files) {
                const date = new Date(file.stat.ctime);
                const dateKey = date.toISOString().split("T")[0]; // YYYY-MM-DD format
                fileCounts[dateKey] = (fileCounts[dateKey] || 0) + 1;
            }
            const outputContent = this.generateReport(fileCounts);
            yield this.writeToFile("markdown-file-tracker.md", outputContent);
        });
    }
    generateReport(fileCounts) {
        const sortedDates = Object.keys(fileCounts).sort();
        let report = "# Markdown File Creation Report\n\n";
        report += "| Date       | Count |\n";
        report += "|------------|-------|\n";
        for (const date of sortedDates) {
            report += `| ${date} | ${fileCounts[date]} |\n`;
        }
        return report;
    }
    writeToFile(fileName, content) {
        return __awaiter(this, void 0, void 0, function* () {
            const existingFile = this.app.vault.getAbstractFileByPath(fileName);
            if (existingFile instanceof obsidian_1.TFile) {
                yield this.app.vault.modify(existingFile, content);
            }
            else {
                yield this.app.vault.create(fileName, content);
            }
        });
    }
}
exports.default = MarkdownFileTracker;
