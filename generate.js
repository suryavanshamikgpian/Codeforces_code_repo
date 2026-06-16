const pptxgen = require("pptxgenjs");

const pres = new pptxgen();
pres.layout = "LAYOUT_16x9";
pres.title = "GSE125345 DESeq2 Analysis";
pres.author = "Suryavansham Sahoo";

// ── Palette ──────────────────────────────────────────────
const NAVY = "1A2E4A";   // dominant dark
const TEAL = "028090";   // accent
const LTEAL = "02C39A";   // highlight
const WHITE = "FFFFFF";
const CREAM = "F4F8FB";
const MUTED = "7A8EA8";
const RED = "E05252";
const GREEN = "3CAA6E";
const TEXT = "1E2D3D";

// ── Helper: slide number ──────────────────────────────────
let slideNum = 0;
function addSlideNum(slide, n) {
    slide.addText(`${n < 10 ? "0" + n : n}`, {
        x: 9.4, y: 5.2, w: 0.5, h: 0.3,
        fontSize: 10, color: MUTED, align: "right"
    });
}

// ── Helper: content slide base ────────────────────────────
function contentSlide(title, icon) {
    slideNum++;
    const slide = pres.addSlide();
    slide.background = { color: WHITE };
    // Left accent bar
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0, y: 0, w: 0.07, h: 5.625,
        fill: { color: NAVY }, line: { color: NAVY }
    });
    // Top banner
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.07, y: 0, w: 9.93, h: 0.85,
        fill: { color: NAVY }, line: { color: NAVY }
    });
    slide.addText(title, {
        x: 0.35, y: 0.12, w: 8.5, h: 0.6,
        fontSize: 22, bold: true, color: WHITE, fontFace: "Calibri", margin: 0
    });
    // Teal accent dot
    slide.addShape(pres.shapes.OVAL, {
        x: 9.1, y: 0.22, w: 0.4, h: 0.4,
        fill: { color: TEAL }, line: { color: TEAL }
    });
    addSlideNum(slide, slideNum);
    return slide;
}

// ══════════════════════════════════════════════════════════
// SLIDE 1 — Title
// ══════════════════════════════════════════════════════════
{
    const slide = pres.addSlide();
    slide.background = { color: NAVY };

    // Large teal rectangle behind title
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0, y: 1.5, w: 10, h: 2.7,
        fill: { color: TEAL, transparency: 85 }, line: { color: TEAL, transparency: 85 }
    });

    // Accent left bar
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0, y: 0, w: 0.25, h: 5.625,
        fill: { color: LTEAL }, line: { color: LTEAL }
    });

    slide.addText("Differential Gene Expression Analysis", {
        x: 0.5, y: 1.1, w: 9, h: 0.75,
        fontSize: 30, bold: true, color: WHITE, fontFace: "Calibri", align: "center"
    });
    slide.addText("of Hematopoietic Stem Cells", {
        x: 0.5, y: 1.85, w: 9, h: 0.65,
        fontSize: 26, bold: true, color: LTEAL, fontFace: "Calibri", align: "center"
    });
    slide.addText("GSE125345  —  DESeq2 Analysis", {
        x: 0.5, y: 2.6, w: 9, h: 0.45,
        fontSize: 15, color: "B0C8D8", fontFace: "Calibri", align: "center", italic: true
    });

    // Divider
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 3, y: 3.2, w: 4, h: 0.04,
        fill: { color: LTEAL }, line: { color: LTEAL }
    });

    slide.addText([
        { text: "Name : ", options: { bold: true, color: "B0C8D8" } },
        { text: "Suryavansham Sahoo", options: { color: WHITE } },
    ], { x: 2.5, y: 3.4, w: 5, h: 0.4, fontSize: 13, fontFace: "Calibri", align: "center" });

    slide.addText([
        { text: "Roll No : ", options: { bold: true, color: "B0C8D8" } },
        { text: "23BT30032", options: { color: WHITE } },
    ], { x: 2.5, y: 3.8, w: 5, h: 0.4, fontSize: 13, fontFace: "Calibri", align: "center" });

    slide.addText([
        { text: "Subject : ", options: { bold: true, color: "B0C8D8" } },
        { text: "Bioinformatics Lab", options: { color: WHITE } },
    ], { x: 2.5, y: 4.2, w: 5, h: 0.4, fontSize: 13, fontFace: "Calibri", align: "center" });
}

// ══════════════════════════════════════════════════════════
// SLIDE 2 — Objective
// ══════════════════════════════════════════════════════════
{
    slideNum++;
    const slide = pres.addSlide();
    slide.background = { color: WHITE };
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0, y: 0, w: 0.07, h: 5.625, fill: { color: NAVY }, line: { color: NAVY }
    });
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.07, y: 0, w: 9.93, h: 0.85, fill: { color: NAVY }, line: { color: NAVY }
    });
    slide.addText("Objective", {
        x: 0.35, y: 0.12, w: 8.5, h: 0.6, fontSize: 22, bold: true, color: WHITE, fontFace: "Calibri", margin: 0
    });
    slide.addShape(pres.shapes.OVAL, {
        x: 9.1, y: 0.22, w: 0.4, h: 0.4, fill: { color: TEAL }, line: { color: TEAL }
    });
    addSlideNum(slide, slideNum);

    // Main goal box
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.35, y: 1.0, w: 9.3, h: 0.85,
        fill: { color: TEAL, transparency: 88 }, line: { color: TEAL, transparency: 40 }
    });
    slide.addText("Main Goal", {
        x: 0.5, y: 1.05, w: 2, h: 0.35, fontSize: 11, bold: true, color: TEAL, fontFace: "Calibri", margin: 0
    });
    slide.addText("Identify and characterise differentially expressed genes between Long-Term Hematopoietic Stem Cells (LT-HSCs) and Short-Term Hematopoietic Stem Cells (ST-HSCs) using RNA-sequencing data from human cord blood–derived hematopoietic populations.", {
        x: 0.5, y: 1.4, w: 9.1, h: 0.4, fontSize: 12, color: TEXT, fontFace: "Calibri", margin: 0
    });

    const aims = [
        ["Molecular Markers", "Identify critical molecular markers and regulatory networks distinguishing long-term self-renewal from short-lived proliferative potential."],
        ["Hierarchical Architecture", "Understand haematopoiesis hierarchy by uncovering expression changes as stem cells migrate towards lineage-committed progenitor states."],
        ["Regulatory Networks", "Identify genes, signalling networks and transcriptional regulators controlling stem cell maintenance, differentiation and destiny."],
    ];

    aims.forEach(([title, body], i) => {
        const y = 2.05 + i * 1.0;
        // Left teal circle with number
        slide.addShape(pres.shapes.OVAL, {
            x: 0.35, y: y + 0.1, w: 0.45, h: 0.45,
            fill: { color: TEAL }, line: { color: TEAL }
        });
        slide.addText(`${i + 1}`, {
            x: 0.35, y: y + 0.1, w: 0.45, h: 0.45,
            fontSize: 14, bold: true, color: WHITE, align: "center", valign: "middle", fontFace: "Calibri", margin: 0
        });
        slide.addText(title, {
            x: 0.95, y: y + 0.04, w: 8.5, h: 0.3, fontSize: 13, bold: true, color: NAVY, fontFace: "Calibri", margin: 0
        });
        slide.addText(body, {
            x: 0.95, y: y + 0.34, w: 8.5, h: 0.55, fontSize: 11, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 3 — Dataset Description
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Dataset Description");

    // Two-column grid of info cards
    const cards = [
        ["Organism", "Homo sapiens"],
        ["Tissue Source", "Human cord blood"],
        ["Platform", "Illumina HiSeq 2500"],
        ["Experiment", "RNA-seq (expression profiling)"],
        ["Total Samples", "15"],
        ["Replicates/Group", "3"],
        ["Cell Types", "LT-HSC, ST-HSC, CMP, GMP, MLP"],
        ["Genes Analyzed", "29,379"],
        ["GEO Accession", "GSE125345"],
        ["FDR Threshold", "10% (padj < 0.10)"],
    ];

    cards.forEach(([label, val], i) => {
        const col = i % 2;
        const row = Math.floor(i / 2);
        const x = 0.3 + col * 4.85;
        const y = 1.0 + row * 0.88;
        slide.addShape(pres.shapes.RECTANGLE, {
            x, y, w: 4.6, h: 0.74,
            fill: { color: row % 2 === 0 ? CREAM : WHITE },
            line: { color: "D0DCE8", pt: 1 }
        });
        slide.addShape(pres.shapes.RECTANGLE, {
            x, y, w: 0.07, h: 0.74,
            fill: { color: TEAL }, line: { color: TEAL }
        });
        slide.addText(label, {
            x: x + 0.18, y: y + 0.06, w: 2.2, h: 0.28,
            fontSize: 10, bold: true, color: MUTED, fontFace: "Calibri", margin: 0
        });
        slide.addText(val, {
            x: x + 0.18, y: y + 0.34, w: 4.3, h: 0.3,
            fontSize: 12, bold: true, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 4 — Results Overview
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Results Overview");

    // Big stat cards
    const stats = [
        ["Total Genes Tested", "29,379", "100%", NAVY],
        ["Significant DEGs", "365", "1.24%", TEAL],
        ["Upregulated (LFC > 0)", "192", "0.65%", GREEN],
        ["Downregulated (LFC < 0)", "173", "0.59%", RED],
    ];

    stats.forEach(([label, num, pct, color], i) => {
        const x = 0.3 + i * 2.38;
        slide.addShape(pres.shapes.RECTANGLE, {
            x, y: 1.0, w: 2.2, h: 2.4,
            fill: { color: WHITE }, line: { color: "D0DCE8", pt: 1 },
            shadow: { type: "outer", blur: 8, offset: 2, angle: 135, color: "000000", opacity: 0.08 }
        });
        slide.addShape(pres.shapes.RECTANGLE, {
            x, y: 1.0, w: 2.2, h: 0.12,
            fill: { color: color }, line: { color: color }
        });
        slide.addText(num, {
            x, y: 1.25, w: 2.2, h: 0.9,
            fontSize: 40, bold: true, color: color, align: "center", fontFace: "Calibri", margin: 0
        });
        slide.addText(`(${pct})`, {
            x, y: 2.15, w: 2.2, h: 0.35,
            fontSize: 14, color: MUTED, align: "center", fontFace: "Calibri", margin: 0
        });
        slide.addText(label, {
            x: x + 0.1, y: 2.55, w: 2.0, h: 0.65,
            fontSize: 11, bold: true, color: TEXT, align: "center", fontFace: "Calibri"
        });
    });

    // Notes box
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.3, y: 3.65, w: 9.4, h: 0.65,
        fill: { color: TEAL, transparency: 90 }, line: { color: TEAL, transparency: 60 }
    });
    slide.addText("Quality Notes:  171 outliers (0.58%) detected | 7,924 low-count genes (27%) filtered (mean count < 4) | FDR threshold: adjusted p-value < 0.10", {
        x: 0.5, y: 3.74, w: 9.0, h: 0.45, fontSize: 11, color: NAVY, fontFace: "Calibri", italic: true, margin: 0
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 5 — Top DEGs
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Top Differentially Expressed Genes");

    const headers = [
        [{ text: "Gene", options: { bold: true, color: WHITE } },
        { text: "Direction", options: { bold: true, color: WHITE } },
        { text: "log₂ FC", options: { bold: true, color: WHITE } },
        { text: "Adj. p-value", options: { bold: true, color: WHITE } }]
    ];

    const rows = [
        ["AC002454.1", "↑ Up", "2.69", "3.9 × 10⁻¹³"],
        ["AC123912.4", "↑ Up", "3.33", "2.0 × 10⁻¹¹"],
        ["CDK6", "↑ Up", "1.25", "1.28 × 10⁻⁷"],
        ["TGFBI", "↑ Up", "9.44", "1.12 × 10⁻⁶"],
        ["DUSP10", "↑ Up", "1.67", "1.12 × 10⁻⁶"],
        ["SOX17", "↓ Down", "-29.57", "1.24 × 10⁻⁶"],
        ["FRMD7", "↓ Down", "-28.67", "3.64 × 10⁻⁶"],
        ["ABCA1", "↑ Up", "2.22", "7.04 × 10⁻⁶"],
        ["MFAP4", "↓ Down", "-1.51", "7.92 × 10⁻⁶"],
        ["CPA3", "↑ Up", "3.19", "8.19 × 10⁻⁶"],
    ];

    const tableRows = [
        headers[0],
        ...rows.map(([gene, dir, lfc, padj]) => [
            { text: gene, options: { bold: true, color: TEXT } },
            { text: dir, options: { color: dir.includes("Up") ? GREEN : RED, bold: true } },
            { text: lfc, options: { color: dir.includes("Up") ? GREEN : RED } },
            { text: padj, options: { color: TEXT } },
        ])
    ];

    slide.addTable(tableRows, {
        x: 0.7, y: 1.0, w: 8.6, h: 4.3,
        fontFace: "Calibri", fontSize: 12,
        align: "center",
        colW: [2.2, 1.8, 1.8, 2.8],
        rowH: 0.36,
        border: { pt: 0.5, color: "D0DCE8" },
        fill: { color: WHITE },
    });

    // Manually color header row
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.7, y: 1.0, w: 8.6, h: 0.36,
        fill: { color: NAVY }, line: { color: NAVY }
    });
    slide.addText([
        { text: "Gene", options: { w: 2.2 } },
        { text: "Direction", options: {} },
        { text: "log₂ FC", options: {} },
        { text: "Adj. p-value", options: {} },
    ].map(o => ({ text: o.text, options: { bold: true, color: WHITE } })),
        { x: 0.7, y: 1.0, w: 8.6, h: 0.36, fontSize: 13, color: WHITE, bold: true, fontFace: "Calibri", align: "center", valign: "middle", margin: 0 });

    // Re-add as table with proper header coloring
    const finalRows = [
        [
            { text: "Gene", options: { bold: true, color: WHITE, fill: { color: NAVY } } },
            { text: "Direction", options: { bold: true, color: WHITE, fill: { color: NAVY } } },
            { text: "log₂ FC", options: { bold: true, color: WHITE, fill: { color: NAVY } } },
            { text: "Adj. p-value", options: { bold: true, color: WHITE, fill: { color: NAVY } } },
        ],
        ...rows.map(([gene, dir, lfc, padj], idx) => [
            { text: gene, options: { bold: true, color: TEXT, fill: { color: idx % 2 === 0 ? WHITE : CREAM } } },
            { text: dir, options: { color: dir.includes("Up") ? GREEN : RED, bold: true, fill: { color: idx % 2 === 0 ? WHITE : CREAM } } },
            { text: lfc, options: { color: dir.includes("Up") ? GREEN : RED, fill: { color: idx % 2 === 0 ? WHITE : CREAM } } },
            { text: padj, options: { color: TEXT, fill: { color: idx % 2 === 0 ? WHITE : CREAM } } },
        ])
    ];

    slide.addTable(finalRows, {
        x: 0.7, y: 1.0, w: 8.6,
        fontFace: "Calibri", fontSize: 12,
        align: "center",
        colW: [2.2, 1.8, 1.8, 2.8],
        rowH: 0.38,
        border: { pt: 0.5, color: "D0DCE8" },
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 6 — PCA Plot
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("PCA Plot");

    // Image placeholder
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.8, y: 1.05, w: 5.6, h: 3.85,
        fill: { color: CREAM }, line: { color: "C0D0E0", pt: 1.5 }
    });
    slide.addText("[ IMAGE PLACEHOLDER ]", {
        x: 0.8, y: 2.5, w: 5.6, h: 0.5,
        fontSize: 13, color: MUTED, bold: true, align: "center", fontFace: "Calibri", margin: 0
    });
    slide.addText("PCA Plot — to be inserted here", {
        x: 0.8, y: 3.05, w: 5.6, h: 0.4,
        fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri", italic: true, margin: 0
    });

    // Key observations box
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 3.85,
        fill: { color: CREAM }, line: { color: "D0DCE8", pt: 1 }
    });
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 0.1,
        fill: { color: TEAL }, line: { color: TEAL }
    });
    slide.addText("Key Observations", {
        x: 6.8, y: 1.18, w: 2.8, h: 0.35,
        fontSize: 12, bold: true, color: TEAL, fontFace: "Calibri", margin: 0
    });

    const obs = [
        ["PC1 Variance", "44% of total variance"],
        ["PC2 Variance", "24% of total variance"],
        ["LT-HSC / ST-HSC", "Distinct, well-separated clusters"],
        ["All 5 Cell Types", "Form separate groups"],
        ["Conclusion", "Strong transcriptional diversity confirmed"],
    ];
    obs.forEach(([key, val], i) => {
        slide.addShape(pres.shapes.OVAL, {
            x: 6.82, y: 1.68 + i * 0.6, w: 0.12, h: 0.12,
            fill: { color: LTEAL }, line: { color: LTEAL }
        });
        slide.addText(key + ":", {
            x: 7.05, y: 1.62 + i * 0.6, w: 2.55, h: 0.25,
            fontSize: 10, bold: true, color: NAVY, fontFace: "Calibri", margin: 0
        });
        slide.addText(val, {
            x: 7.05, y: 1.87 + i * 0.6, w: 2.55, h: 0.28,
            fontSize: 10, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 7 — MA Plot
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("MA Plot — Expression vs Fold Change");

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.8, y: 1.05, w: 5.6, h: 3.85,
        fill: { color: CREAM }, line: { color: "C0D0E0", pt: 1.5 }
    });
    slide.addText("[ IMAGE PLACEHOLDER ]", {
        x: 0.8, y: 2.5, w: 5.6, h: 0.5,
        fontSize: 13, color: MUTED, bold: true, align: "center", fontFace: "Calibri", margin: 0
    });
    slide.addText("MA Plot — to be inserted here", {
        x: 0.8, y: 3.05, w: 5.6, h: 0.4,
        fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri", italic: true, margin: 0
    });

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 3.85,
        fill: { color: CREAM }, line: { color: "D0DCE8", pt: 1 }
    });
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 0.1,
        fill: { color: TEAL }, line: { color: TEAL }
    });
    slide.addText("Key Observations", {
        x: 6.8, y: 1.18, w: 2.8, h: 0.35,
        fontSize: 12, bold: true, color: TEAL, fontFace: "Calibri", margin: 0
    });

    const obs = [
        "Most genes centred around LFC = 0 (no change).",
        "Significant genes (blue) concentrated at moderate expression levels.",
        "SOX17: strong downregulation (LFC ≈ −29.57).",
        "TGFBI: strong upregulation (LFC ≈ +9.44).",
        "Typical MA fan-shape: larger variance at low counts.",
    ];
    obs.forEach((text, i) => {
        slide.addShape(pres.shapes.OVAL, {
            x: 6.82, y: 1.7 + i * 0.6, w: 0.12, h: 0.12,
            fill: { color: LTEAL }, line: { color: LTEAL }
        });
        slide.addText(text, {
            x: 7.05, y: 1.63 + i * 0.6, w: 2.55, h: 0.48,
            fontSize: 10, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 8 — Volcano Plot
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Volcano Plot — Significance vs Magnitude");

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.8, y: 1.05, w: 5.6, h: 3.85,
        fill: { color: CREAM }, line: { color: "C0D0E0", pt: 1.5 }
    });
    slide.addText("[ IMAGE PLACEHOLDER ]", {
        x: 0.8, y: 2.5, w: 5.6, h: 0.5,
        fontSize: 13, color: MUTED, bold: true, align: "center", fontFace: "Calibri", margin: 0
    });
    slide.addText("Volcano Plot — to be inserted here", {
        x: 0.8, y: 3.05, w: 5.6, h: 0.4,
        fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri", italic: true, margin: 0
    });

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 3.85,
        fill: { color: CREAM }, line: { color: "D0DCE8", pt: 1 }
    });
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.7, y: 1.05, w: 3.0, h: 0.1,
        fill: { color: TEAL }, line: { color: TEAL }
    });
    slide.addText("Key Genes", {
        x: 6.8, y: 1.18, w: 2.8, h: 0.35,
        fontSize: 12, bold: true, color: TEAL, fontFace: "Calibri", margin: 0
    });

    slide.addText("Upregulated:", {
        x: 6.9, y: 1.65, w: 2.6, h: 0.3, fontSize: 11, bold: true, color: GREEN, fontFace: "Calibri", margin: 0
    });
    ["CDK6", "DUSP10", "CPA3", "TGFBI", "AC002454.1"].forEach((gene, i) => {
        slide.addShape(pres.shapes.OVAL, {
            x: 6.95, y: 2.06 + i * 0.34, w: 0.1, h: 0.1,
            fill: { color: GREEN }, line: { color: GREEN }
        });
        slide.addText(gene, {
            x: 7.15, y: 2.0 + i * 0.34, w: 2.4, h: 0.28,
            fontSize: 10, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });

    slide.addText("Downregulated:", {
        x: 6.9, y: 3.75, w: 2.6, h: 0.3, fontSize: 11, bold: true, color: RED, fontFace: "Calibri", margin: 0
    });
    ["SOX17", "FRMD7", "MFAP4"].forEach((gene, i) => {
        slide.addShape(pres.shapes.OVAL, {
            x: 6.95, y: 4.15 + i * 0.3, w: 0.1, h: 0.1,
            fill: { color: RED }, line: { color: RED }
        });
        slide.addText(gene, {
            x: 7.15, y: 4.1 + i * 0.3, w: 2.4, h: 0.28,
            fontSize: 10, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });

    slide.addText("Thresholds: adj. p-value < 0.1  &  |log₂FC| > 1  |  Total = 29,379 variables", {
        x: 0.8, y: 5.1, w: 8.4, h: 0.3,
        fontSize: 10, color: MUTED, fontFace: "Calibri", italic: true, margin: 0
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 9 — Heatmap
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Heatmap — Top DEGs");

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0.3, y: 1.05, w: 5.8, h: 3.85,
        fill: { color: CREAM }, line: { color: "C0D0E0", pt: 1.5 }
    });
    slide.addText("[ IMAGE PLACEHOLDER ]", {
        x: 0.3, y: 2.6, w: 5.8, h: 0.5,
        fontSize: 13, color: MUTED, bold: true, align: "center", fontFace: "Calibri", margin: 0
    });
    slide.addText("Heatmap of Top DEGs — to be inserted here", {
        x: 0.3, y: 3.15, w: 5.8, h: 0.4,
        fontSize: 11, color: MUTED, align: "center", fontFace: "Calibri", italic: true, margin: 0
    });

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.35, y: 1.05, w: 3.35, h: 3.85,
        fill: { color: CREAM }, line: { color: "D0DCE8", pt: 1 }
    });
    slide.addShape(pres.shapes.RECTANGLE, {
        x: 6.35, y: 1.05, w: 3.35, h: 0.1,
        fill: { color: TEAL }, line: { color: TEAL }
    });
    slide.addText("Observations", {
        x: 6.45, y: 1.18, w: 3.1, h: 0.35,
        fontSize: 12, bold: true, color: TEAL, fontFace: "Calibri", margin: 0
    });

    const obs = [
        "Top 30 DEGs shown across all 15 samples.",
        "Clear clustering by cell type (LT-HSC, ST-HSC, CMP, GMP, MLP).",
        "GYG1 & SPP1: highest expression in LT-HSC.",
        "CPA3, SPTBN2: elevated in CMP/GMP.",
        "Hierarchical clustering confirms cell-type separation.",
        "Row-scaled z-scores highlight relative expression.",
    ];
    obs.forEach((text, i) => {
        slide.addShape(pres.shapes.OVAL, {
            x: 6.47, y: 1.73 + i * 0.52, w: 0.12, h: 0.12,
            fill: { color: LTEAL }, line: { color: LTEAL }
        });
        slide.addText(text, {
            x: 6.7, y: 1.66 + i * 0.52, w: 2.85, h: 0.46,
            fontSize: 10, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 10 — Key Inferences
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Key Inferences");

    const inferences = [
        ["1. Transcriptional Distinction", "PCA and heatmap confirm LT-HSC and ST-HSC form distinct clusters with significantly different expression profiles."],
        ["2. Loss of Stemness in ST-HSC", "SOX17 is strongly downregulated (LFC ≈ −29.57) in ST-HSC, indicating loss of stem-cell maintenance signals and increased differentiation."],
        ["3. Increased Proliferation Signals", "CDK6 upregulation in ST-HSC suggests increased cell-cycle activity, consistent with actively dividing progenitor cells."],
        ["4. Differentiation Pathway Activation", "TGFBI and DUSP10 upregulation indicates activation of signalling and regulatory programs driving lineage commitment."],
        ["5. Moderate Expression Dominates DEGs", "Most significant genes fall in moderate expression ranges — condition-specific regulation, not housekeeping gene changes."],
    ];

    inferences.forEach(([title, body], i) => {
        const y = 1.0 + i * 0.88;
        const isUp = i % 2 === 0;
        slide.addShape(pres.shapes.RECTANGLE, {
            x: 0.3, y, w: 9.4, h: 0.78,
            fill: { color: isUp ? CREAM : WHITE }, line: { color: "D0DCE8", pt: 0.5 }
        });
        slide.addShape(pres.shapes.RECTANGLE, {
            x: 0.3, y, w: 0.07, h: 0.78,
            fill: { color: TEAL }, line: { color: TEAL }
        });
        slide.addText(title, {
            x: 0.5, y: y + 0.06, w: 9.0, h: 0.3,
            fontSize: 12, bold: true, color: NAVY, fontFace: "Calibri", margin: 0
        });
        slide.addText(body, {
            x: 0.5, y: y + 0.37, w: 9.0, h: 0.36,
            fontSize: 11, color: TEXT, fontFace: "Calibri", margin: 0
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 11 — Annexure Code
// ══════════════════════════════════════════════════════════
{
    const slide = contentSlide("Annexure — Key Code");

    const codeBlocks = [
        ["Package Loading", "library(DESeq2); library(ggplot2)\nlibrary(pheatmap); library(EnhancedVolcano)"],
        ["Load & Prepare Data", 'counts <- read.table("data.tsv", header=TRUE, sep="\\t")\nrownames(counts) <- make.unique(as.character(counts[,1]))\ncounts <- counts[,-1]\ncounts <- round(counts[, sapply(counts, is.numeric)])'],
        ["DESeq2 Pipeline", 'dds <- DESeqDataSetFromMatrix(countData=counts, colData=coldata, design=~condition)\ndds <- dds[rowSums(counts(dds))>=10,]\ndds <- DESeq(dds)\nres <- results(dds, contrast=c("condition","ST_HSC","LT_HSC"), alpha=0.1)'],
        ["Visualisations", 'vsd <- vst(dds, blind=FALSE)\nplotPCA(vsd, intgroup="condition")   # PCA\nplotMA(res)                           # MA plot\nEnhancedVolcano(res, lab=rownames(res), x="log2FoldChange", y="pvalue")\npheatmap(assay(vsd)[order(res$pvalue)[1:50],], scale="row")  # Heatmap'],
    ];

    const cols = [[0, 1], [2, 3]];
    cols.forEach((pair, col) => {
        pair.forEach((idx, row) => {
            const [header, code] = codeBlocks[idx];
            const x = 0.3 + col * 4.85;
            const y = 1.0 + row * 2.15;
            slide.addShape(pres.shapes.RECTANGLE, {
                x, y, w: 4.6, h: 2.0,
                fill: { color: "1E2D3D" }, line: { color: TEAL, pt: 1 }
            });
            slide.addText(header, {
                x: x + 0.12, y: y + 0.08, w: 4.35, h: 0.32,
                fontSize: 11, bold: true, color: LTEAL, fontFace: "Calibri", margin: 0
            });
            slide.addText(code, {
                x: x + 0.12, y: y + 0.42, w: 4.35, h: 1.5,
                fontSize: 9, color: "D0E8FF", fontFace: "Consolas", margin: 0
            });
        });
    });
}

// ══════════════════════════════════════════════════════════
// SLIDE 12 — Thank You
// ══════════════════════════════════════════════════════════
{
    const slide = pres.addSlide();
    slide.background = { color: NAVY };

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 0, y: 0, w: 0.25, h: 5.625,
        fill: { color: LTEAL }, line: { color: LTEAL }
    });

    slide.addText("Thank You", {
        x: 0.5, y: 1.2, w: 9, h: 1.1,
        fontSize: 54, bold: true, color: WHITE, fontFace: "Calibri", align: "center"
    });

    slide.addShape(pres.shapes.RECTANGLE, {
        x: 3, y: 2.5, w: 4, h: 0.06,
        fill: { color: LTEAL }, line: { color: LTEAL }
    });

    const summary = [
        ["365", "Significant DEGs (FDR < 10%)"],
        ["192", "Upregulated genes"],
        ["173", "Downregulated genes"],
    ];
    summary.forEach(([num, label], i) => {
        const x = 1.8 + i * 2.8;
        slide.addText(num, {
            x, y: 2.8, w: 2.4, h: 0.7,
            fontSize: 36, bold: true, color: LTEAL, align: "center", fontFace: "Calibri", margin: 0
        });
        slide.addText(label, {
            x, y: 3.5, w: 2.4, h: 0.5,
            fontSize: 12, color: "B0C8D8", align: "center", fontFace: "Calibri", margin: 0
        });
    });

    slide.addText("Key Finding: Strong transcriptional separation between LT-HSC and ST-HSC — SOX17 loss and CDK6 gain mark the stemness-to-proliferation transition.", {
        x: 1.0, y: 4.3, w: 8.0, h: 0.7,
        fontSize: 12, color: "B0C8D8", align: "center", fontFace: "Calibri", italic: true
    });
}

pres.writeFile({ fileName: "./outputs/GSE125345_DESeq2_Presentation.pptx" })
    .then(() => console.log("Done!"))
    .catch(e => console.error(e));