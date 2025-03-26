import { App, Plugin, TFile } from "obsidian";

export default class MarkdownFileTracker extends Plugin {
  async onload() {
    console.log("Markdown File Tracker Loaded");
    this.trackMarkdownFiles();
  }

  async trackMarkdownFiles() {
    const fileCounts: Record<string, number> = {};
    const files = this.app.vault.getFiles().filter(f => f.extension === "md");

    for (const file of files) {
      const date = new Date(file.stat.ctime);
      const dateKey = date.toISOString().split("T")[0]; // YYYY-MM-DD format
      fileCounts[dateKey] = (fileCounts[dateKey] || 0) + 1;
    }

    console.log("Markdown Files by Date:", fileCounts);
  }
}

