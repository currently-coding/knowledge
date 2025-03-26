import { App, Plugin, TFile } from "obsidian";

export default class MarkdownFileTracker extends Plugin {
  async onload() {
    console.log("Markdown File Tracker Loaded");
    await this.trackMarkdownFiles();
  }

  async trackMarkdownFiles() {
    const fileCounts: Record<string, number> = {};
    const files = this.app.vault.getFiles().filter(f => f.extension === "md");

    for (const file of files) {
      const date = new Date(file.stat.ctime);
      const dateKey = date.toISOString().split("T")[0]; // YYYY-MM-DD format
      fileCounts[dateKey] = (fileCounts[dateKey] || 0) + 1;
    }

    const outputContent = this.generateReport(fileCounts);
    await this.writeToFile("markdown-file-tracker.md", outputContent);
  }

  generateReport(fileCounts: Record<string, number>): string {
    const sortedDates = Object.keys(fileCounts).sort();
    let report = "# Markdown File Creation Report\n\n";
    report += "| Date       | Count |\n";
    report += "|------------|-------|\n";
    for (const date of sortedDates) {
      report += `| ${date} | ${fileCounts[date]} |\n`;
    }
    return report;
  }

  async writeToFile(fileName: string, content: string) {
    const existingFile = this.app.vault.getAbstractFileByPath(fileName);
    if (existingFile instanceof TFile) {
      await this.app.vault.modify(existingFile, content);
    } else {
      await this.app.vault.create(fileName, content);
    }
  }
}

